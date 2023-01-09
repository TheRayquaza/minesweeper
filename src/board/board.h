#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include <stdexcept>
#include <random>
#include <functional>

#include "../cell/cell.h"
#include "../enums/state.h"

using namespace std;

class Board
{
    private :

        long rows;
        long cols;
        list<Cell *> cell_list; // Row-major order
        State state;

    public :
        
        // Constructor
        Board(long rows, long cols);

        // Getter
        long get_rows() const;
        long get_cols() const;
        State get_state() const;

        // Setter
        void set_rows(long rows);
        void set_cols(long cols);
        void set_state(State state);

        // Methods
        void discover_cell(long row, long col);
        void set_mines_cell(void);
        int feed_board_random();

        Cell * get_nth_element(long n) const;
        int count_invalid_neighbours(long row, long col) const;
        void display_board(bool solved = false) const;
        bool is_cell_valid(long row,  long col) const;
        bool all_mines_marked() const;

        // Destructor
        ~Board();

};