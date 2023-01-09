//
// Created by mateo on 1/8/23.
//
#include <err.h>

#include "game/game.h"

#define ROWS_DEFAULT 10
#define COLS_DEFAULT 10

using namespace std;

int main(int argc, char * argv[])
{
    srand(time(NULL));

    Game * game;

    if (argc == 1)
        game = new Game(ROWS_DEFAULT, COLS_DEFAULT);
    else if (argc == 3)
        game = new Game(::strtoul(argv[1], NULL, 10), ::strtoul(argv[2], NULL,  10));
    else
        errx(EXIT_FAILURE, "Invalid amount of argument given ! Should be 0 or 2 (rows, cols)");

    game->play();

    cout << "Here is the solved board : \n";
    game->get_board()->display_board(true);

    delete game;
}