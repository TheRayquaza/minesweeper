/*
 * =====================================================================================
 *
 *       Filename:  board.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2023 12:01:29 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Mateo Lelong,
 *   Organization:  
 *
 * =====================================================================================
 */

#include "board.h"

using namespace std;

// Constructor

Board::Board()
{
    this->rows = 10;
    this->cols = 10;
    this->cell_list = {};
    this->lost = false;
}

Board::Board(unsigned long rows, unsigned long cols)
{
    this->rows = rows;
    this->cols = cols;
    this->cell_list = {};
    this->lost = false;

    for (unsigned long i = 0; i < rows*cols; i++)
        this->cell_list.push_back(new Cell(' '));
}

Board::Board(unsigned long rows, unsigned long cols, list<char> cells)
{
    this->rows = rows;
    this->cols = cols;
    this->cell_list = {};
    this->lost = true;

    list<char>::iterator it;
    for (it = cells.begin(); it != cells.end(); it++)
        this->cell_list.push_back(new Cell(*it));
}

// Getter
unsigned long Board::get_rows()
{
    return this->rows;
};
unsigned long Board::get_cols()
{
    return this->cols;
};

bool Board::get_lost()
{
    return this->lost;
};

// Setter
void Board::set_rows(unsigned long rows)
{
    this->rows = rows;
};
void Board::set_cols(unsigned long cols)
{
    this->cols = cols;
};

void Board::set_lost(bool lost) {
    this->lost = lost;
}

// Methods
Cell * Board::get_nth_element(unsigned long n)
{
    if (n >= this->cell_list.size())
        throw std::invalid_argument( "received negative value" );
    auto it = this->cell_list.begin();
    for (unsigned long i = 0; i < n; i++, it++);

    return *it;
}

void Board::display_board()
{
    unsigned long i = 0;
    for (auto it = this->cell_list.begin(); it != this->cell_list.end(); it++, i++)
    {
        if (i % this->get_cols() == 0)
            cout << '\n';
        (*it)->display_cell();
    }
    cout << '\n';
}

void Board::discover_cell(unsigned long row, unsigned long col, bool is_origin)
{
    Cell * cell = this->get_nth_element(row * this->cols + col);

    if (!cell->get_is_valid())
    {
        if (is_origin)
            this->set_lost(true);
        else
        {

        }
    }
    else
    {

    }
}

void Board::feed_board_random()
{

}

// Destructor
Board::~Board()
{
    for (auto & it : this->cell_list)
        delete it;
}

