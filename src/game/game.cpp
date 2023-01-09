//
// Created by mateo on 1/8/23.
//

#include "game.h"


// Constructor
Game::Game(long row, long col)
{
    this->board = new Board(row, col);
    this->nb_mines = this->board->feed_board_random();
    this->nb_flag = (int)(1.25 * this->nb_mines);
    this->board->set_mines_cell();
}

// Getter
Board * Game::get_board()
{
    return this->board;
}

int Game::get_nb_flag() const
{
    return this->nb_flag;
}

// Setter
void Game::set_nb_flag(int nb_flag)
{
    this->nb_flag = nb_flag;
}

// Methods

void Game::play_one()
{
    string command = "";
    bool is_flag = false;
    while (command != "F" && command != "C")
    {
        cout << "Flag Remaining : [" << this->get_nb_flag() << "]\n"; 
        cout << "Would you like to discover a cell or flag a cell ? [C/F]\n";
        cin >> command;
    }

    is_flag = command == "F";

    cout << "Enter a valid row : ";
    cin >> command;
    long row;
    try 
    {
        row = stol(command);
    }
    catch (const std::exception& e)
    {
        return;
    }


    cout << "Enter a valid column : ";
    cin >> command;
    long col;
    try
    {
        col = stol(command);
    }
    catch(const std::exception& e)
    {
        return;
    }

    if (!is_flag)
    {
        if (!this->get_board()->get_nth_element(row * this->get_board()->get_cols() + col)->get_is_valid())
            this->get_board()->set_state(State::LOST);
        else
            this->get_board()->discover_cell(row, col);
    }
    else
    {
        this->get_board()
        ->get_nth_element(row * this->get_board()->get_cols() + col)
        ->set_state(CellState::FLAGGED);
        this->set_nb_flag(this->get_nb_flag()-1);
    }
}

void Game::play()
{
    while (this->board->get_state() == State::PENDING)
    {
        cout << "Current Board : \n";
        this->board->display_board(false);
        this->play_one();

        if (this->board->all_mines_marked())
            this->get_board()->set_state(State::WIN);
        else if (this->get_nb_flag() == 0)
        {
            cout << "NO FLAG REMAINING\n";
            this->get_board()->set_state(State::LOST);
        }
    }

    if (this->board->get_state() == State::WIN)
        cout << "BRAVO ! You won !\n";
    else
        cout << "You have lost this game ...\n";
    cout << "Exit ...\n";
}

// Destructor
Game::~Game()
{
    delete this->board;
}