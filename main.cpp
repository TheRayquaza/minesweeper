//
// Created by mateo on 1/8/23.
//
#include <err.h>

#include "board/board.h"

#define ROWS_DEFAULT 10
#define COLS_DEFAULT 10

using namespace std;

int main(int argc, char * argv[])
{
    Board * board;

    if (argc == 1)
        board = new Board(ROWS_DEFAULT, COLS_DEFAULT);
    else if (argc == 3)
        board = new Board(::strtoul(argv[1], NULL, 10), ::strtoul(argv[2], NULL,  10));
    else
        errx(EXIT_FAILURE, "Invalid amount of argument given ! Should be 0 or 2 (rows, cols)");



    delete board;
}