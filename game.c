#include "board.h"
#include "check.h"

int main(void){

    //Creates a game board and inititalizes it to all 0s.
    int game_board[NUM_ROWS][NUM_COLS] = {0};

    //Create game loop with the functions I have programmed. 
    //aaaaa it's coming together :DDDD

    int win = 0, turn = 0, tie = 0;

    while(!win){

        print_board(game_board);
        drop_piece(game_board, ((turn % 2) + 1)); turn++;
        win = win_condition(game_board);

        if(whole_board_full(game_board))
            win = -1;

    }

    print_board(game_board);

    

    if(win == -1)
    {
        printf("Tie: no winner.");
    } else if(win == 1) {
        printf("Player 1 wins!");
    } else
        printf("Player 2 wins!");

    return 0;
}