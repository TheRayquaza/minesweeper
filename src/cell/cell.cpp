#include "cell.h"

using namespace std;

// Constructor
Cell::Cell()
{
    this->state = CellState::HIDDEN;
    this->is_valid = true;
    this->nb_mines = 0;
}

// Getter
bool Cell::get_is_valid() const
{
    return this->is_valid;
}

CellState Cell::get_cell_state() const
{
    return this->state;
}

int Cell::get_nb_mines() const
{
    return this->nb_mines;
}

// Setter
void Cell::set_is_valid(bool is_valid)
{
    this->is_valid = is_valid;
}

void Cell::set_state(CellState state)
{
    this->state = state;
}

void Cell::set_nb_mines(int nb_mines)
{
    this->nb_mines = nb_mines;
}

// Methods
void Cell::display_cell()
{
    switch (this->state)
    {
        case CellState::DISCOVERED :
            this->display_solved_cell();
            break;
        case CellState::HIDDEN :

            cout << " " << HIDE << " ";
            break;
        case CellState::FLAGGED :
            cout << " ";
            Style::display_yellow(FLAG);
            cout << " ";
            break; 
    }
}

void Cell::display_solved_cell(void)
{
    cout << " ";
    if (this->is_valid)
    {
        if (this->get_nb_mines() == 0)
            cout << BLANK;
        else 
        {
            if (this->nb_mines < 3)
                Style::display_green(this->nb_mines + '0');
            else if (this->nb_mines < 5)
                Style::display_yellow(this->nb_mines + '0');
            else
                Style::display_red(this->nb_mines + '0');
        }
    }
    else
        Style::display_red(MINE);
    cout << " ";
}

// Destructor
Cell::~Cell()
= default;