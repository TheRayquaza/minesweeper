#pragma once

#include <iostream>

#include "../misc/style.h"
#include "../enums/cell_state.h"

#define FLAG 'F'
#define HIDE 'X'
#define BLANK ' '
#define MINE 'O'

class Cell
{
    public :

        // Constructor
        Cell();

        // Getter
        bool get_is_valid() const;
        CellState get_cell_state() const;
        int get_nb_mines() const;

        // Setter
        void set_is_valid(bool is_valid);
        void set_state(CellState state);
        void set_nb_mines(int nb_mines);

        // Methods
        void display_cell(void);
        void display_solved_cell(void);

        // Destructor
        ~Cell();
    
    private :

        bool is_valid; // no mine
        CellState state;
        int nb_mines; // number of mines around the cell (max is 8 though)
};