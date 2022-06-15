// This will contain all the functions for working with the gameboard.
// The gameboard will be a scalable 2d array defined by macros.

/*

void drop_piece(char, int, array): prints who's turn it is, then drops the character argument into the specified column.
*/

#include "check.h"
#include "board.h"

//All functions go here.

void print_board(int g[][NUM_COLS])
{

    int row = 0, column = 0;

    for(row = 0; row < NUM_ROWS; row++)
    {
        puts("");

        for(column = 0; column < NUM_COLS; column++){

            switch (g[row][column])
            {
                case 0:
                printf("%c ", EMPTY_SPACE); break;
                
                case 1:
                printf("%c ", P1_TOKEN); break;

                case 2:
                printf("%c ", P2_TOKEN); break;
            }     
        }
    }

    puts("");
    for(int i = 0; i < NUM_COLS; i++)
        printf("%d ", i);
    puts("");
}

int is_full(int column, int g[][NUM_COLS])
{
    return g[0][column];
}

int whole_board_full(int g[][NUM_COLS])
{
    for(int i = 0; i < NUM_COLS; i++)
        if(g[0][i] == 0)
            return 0;

    return 1;

}

void drop_piece(int g[][NUM_COLS], int player){

    int choice, row = 0;

    printf("P%d's choice: ", player);
    scanf("%d", &choice);
    
    if(choice >= 0 && choice < NUM_COLS)
        {
            //If column is not full
            if(!is_full(choice, g)){

                //Leaving nothing to chance. Don't want funky array arithmetic to mess up the drop.
                //If the column is empty, then drop it to the bottom.
                if(g[NUM_ROWS - 1][choice] == 0)
                    
                    g[NUM_ROWS - 1][choice] = player;
                
                //Otherwise, do the loop to find the next open spot
                else {

                    while((g[row+1][choice] == 0))
                    row++;

                    g[row][choice] = player;

                }

            //Column is full.
            } else {
            
                puts("Column is full.");
                drop_piece(g, player);
            }
    } else {
        puts("Out of bounds.");
        drop_piece(g, player);
    }

    


}   