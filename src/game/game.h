//
// Created by mateo on 1/8/23.
//

#pragma once
#include <iostream>
#include "../board/board.h"

class Game 
{

    private :
    
        Board * board;
        int nb_flag;
        int nb_mines;

    public :

        // Constructor
        Game(long row, long col);

        // Getter
        Board * get_board();
        int get_nb_flag() const;

        // Setter
        void set_nb_flag(int nb_flag);

        // Methods
        void play_one();
        void play();

 

        // Destructor
        ~Game();
};
