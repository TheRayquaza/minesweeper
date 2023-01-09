#pragma once

#include <iostream>

#define INVALID 'F'
#define VALID ' '

class Cell
{
    public :

        // Constructor
        Cell();
        Cell(char c);

        // Getter
        char get_cell_c() const;
        bool get_is_valid() const;

        // Setter
        void set_cell_c(char cell_c);
        void set_is_valid(bool is_valid);

        // Methods
        void display_cell(void) const;

        // Destructor
        ~Cell();
    
    private :
        char cell_c;
        bool is_valid; // no bomb
};
