#include "cell.h"


using namespace std;

Cell::Cell()
{
    this->cell_c = VALID;
    this->is_valid = true;
}

Cell::Cell(char c)
{
    this->cell_c = c;
    this->is_valid = c == INVALID;
}

// Getter
char Cell::get_cell_c() const
{
    return this->cell_c;
}

bool Cell::get_is_valid() const
{
    return this->is_valid;
}


// Setter
void Cell::set_cell_c(char cell_c)
{
    this->cell_c = cell_c;
}

void Cell::set_is_valid(bool is_valid)
{
    this->is_valid = is_valid;
}

// Methods
void Cell::display_cell() const
{
    cout << "| " << this->cell_c << " |";
}

// Destructor
Cell::~Cell()
= default;