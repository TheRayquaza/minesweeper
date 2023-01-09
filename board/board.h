/*
 * =====================================================================================
 *
 *       Filename:  board.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2023 12:01:39 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include <stdexcept>
#include "../cell/cell.h"

using namespace std;

class Board
{
    private :

        unsigned long rows;
        unsigned long cols;
        list<Cell *> cell_list; // Row-major order
        bool lost;

    public :
        
        // Constructor
        Board();
        Board(unsigned long rows, unsigned long cols);
        Board(unsigned long rows, unsigned long cols, list<char> cells);

        // Getter
        unsigned long get_rows();
        unsigned long get_cols();
        bool get_lost();

        // Setter
        void set_rows(unsigned long rows);
        void set_cols(unsigned long cols);
        void set_lost(bool lost);

        // Methods
        Cell * get_nth_element(unsigned long n);
        void discover_cell(unsigned long row, unsigned long col, bool is_origin = true);
        int count_invalid_neighbours(unsigned long row, unsigned long col);
        void feed_board_random();
        void display_board(void);

        // Destructor
        ~Board();

};