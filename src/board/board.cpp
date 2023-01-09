#include "board.h"

using namespace std;

// Constructor

Board::Board(long rows, long cols)
{
    this->rows = rows;
    this->cols = cols;
    this->cell_list = {};
    this->state = State::PENDING;

    for (long i = 0; i < rows*cols; i++)
        this->cell_list.push_back(new Cell());
}

// Getter
 long Board::get_rows() const
{
    return this->rows;
};

long Board::get_cols() const
{
    return this->cols;
};

State Board::get_state() const
{
    return this->state;
};

// Setter
void Board::set_rows(long rows)
{
    this->rows = rows;
};

void Board::set_cols(long cols)
{
    this->cols = cols;
};

void Board::set_state(State state) 
{
    this->state = state;
};

// Methods
Cell * Board::get_nth_element(long n) const
{
    if (n >= (long)this->cell_list.size() || n < 0)
        throw std::invalid_argument("Received invalid index");

    auto it = this->cell_list.begin();
    for (long i = 0; i < n; i++, it++);

    return *it;
};

void Board::display_board(bool solved) const
{
    cout << "  ";
    for (long i = 0; i < this->cols; i++)
        cout << " " << i << " ";

    long i = 0;
    long j = 0;
    for (auto it = this->cell_list.begin(); it != this->cell_list.end(); it++, i++)
    {
        if (i % this->get_cols() == 0)
        {
            cout << "\n  ";
            for (long k = 0; k < this->cols; k++)
                cout << "---";
            cout << "\n";
            cout << j << " ";
            j++;
        }
        if (solved) (*it)->display_solved_cell();
        else (*it)->display_cell();
    }
    cout << "\n  ";
    for (long k = 0; k < this->cols; k++)
        cout << "---";
    cout << "\n";
};

void Board::discover_cell(long row, long col)
{
    Cell * cell = this->get_nth_element(row * this->cols + col);
    
    if (cell->get_cell_state() == CellState::DISCOVERED || !cell->get_is_valid())
        return;
    
    cell->set_state(CellState::DISCOVERED);

    if (cell->get_nb_mines() == 0)
    {
        if (row+1 < this->rows)
        {
            this->discover_cell(row+1, col);

            if (col+1 < this->cols)
                this->discover_cell(row+1, col+1);
            if (col > 0)
                this->discover_cell(row+1, col-1);
        }
        if (row > 0)
        {
            this->discover_cell(row-1, col);

            if (col+1 < this->cols)
                this->discover_cell(row-1, col+1);
            if (col > 0)
                this->discover_cell(row-1, col-1);
        }
        if (col > 0)
            this->discover_cell(row, col-1);
        if (col+1 < this->cols)
            this->discover_cell(row, col+1);
    }
};

int Board::feed_board_random()
{
    long i, j, nb_cells = rand() % (this->cols * this->rows / 12) + this->cols;
    for (i = 0; i < nb_cells; i++)
    {
        j = rand() % (this->cols * this->rows);
        while (!this->get_nth_element(j)->get_is_valid())
            j = rand() % (this->cols * this->rows);
        this->get_nth_element(j)->set_is_valid(false);
    }
    return (int)nb_cells;
};

int Board::count_invalid_neighbours(long row, long col) const
{
    int count = 0;
    for (long i = row - 1; i != row + 2; i++)
        for (long j = col - 1; j != col + 2; j++)
            if (this->is_cell_valid(i, j) && !(i == row && j == col)
                && !(this->get_nth_element(i * this->cols + j)->get_is_valid()))
                count++;
    return count;
};

bool Board::is_cell_valid(long row, long col) const
{
    return row < this->rows && row >= 0 && col < this->cols && col >= 0;
};

void Board::set_mines_cell(void)
{
    long row = 0, col = 0;
    for (auto it = this->cell_list.begin(); it != this->cell_list.end(); it++, col++)
    {
        if (col == this->cols)
        {
            row++;
            col = 0;
        }
        (*it)->set_nb_mines(this->count_invalid_neighbours(row, col));
    }
}

bool Board::all_mines_marked(void) const
{
    Cell * current;
    for (auto it = this->cell_list.begin(); it != this->cell_list.end(); it++)
    {
        current = *it;
        if (!current->get_is_valid() && current->get_cell_state() != CellState::FLAGGED)
            return false;
    }

    return true;
}


// Destructor
Board::~Board()
{
    for (auto & it : this->cell_list)
        delete it;
};