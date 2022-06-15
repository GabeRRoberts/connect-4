#ifndef BOARD_h
#define BOARD_H

#include <stdio.h>
#include "config.h"

//Prints the board.
void print_board(int g[][NUM_COLS]);

//Drops a piece
void drop_piece(int g[][NUM_COLS], int player);

//Checks if the whole board is full
int whole_board_full(int g[][NUM_COLS]);

#endif
