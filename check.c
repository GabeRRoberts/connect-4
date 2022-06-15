#include "check.h"

    /*
    So with the default parameters of a board, we'd search the following Xs for each kind of win.

    Horizontal          Vertical            Diagonal L          Diagonal R
    X X X X 0 0 0       X X X X X X X       0 0 0 X X X X       X X X X 0 0 0
    X X X X 0 0 0       X X X X X X X       0 0 0 X X X X       X X X X 0 0 0 
    X X X X 0 0 0       X X X X X X X       0 0 0 X X X X       X X X X 0 0 0
    X X X X 0 0 0       0 0 0 0 0 0 0       0 0 0 0 0 0 0       0 0 0 0 0 0 0
    X X X X 0 0 0       0 0 0 0 0 0 0       0 0 0 0 0 0 0       0 0 0 0 0 0 0
    X X X X 0 0 0       0 0 0 0 0 0 0       0 0 0 0 0 0 0       0 0 0 0 0 0 0
    */

int check_horizontal(int g[][NUM_COLS])
{
    //Only use appropriate spaces.
    //Starting coordinates for our search.
    int row = 0, column = 0;
    
    //Cycle through all relevant slots.
    for(row = 0; row < NUM_ROWS; row++)
    {
        for(column = 0; column < (NUM_COLS - 3); column++)
        {
            //Horizontal (right) win condition for player 1.
            if((g[row][column] == 1) && (g[row][column + 1] == 1) && (g[row][column + 2] == 1) && (g[row][column + 3] == 1))
                return 1;

            //Horizontal (right) win condition for player 2.
            if((g[row][column] == 2) && (g[row][column + 1] == 2) && (g[row][column + 2] == 2) && (g[row][column + 3] == 2))
                return 2;
        }
    }
    
    return 0;
}

int check_vertical(int g[][NUM_COLS])
{
    //Only use appropriate spaces.
    //Starting coordinates for our search.
    int row = 0, column = 0;
    
    //Cycle through all relevant slots.
    for(row = 0; row < (NUM_ROWS - 3); row++)
    {
        for(column = 0; column < NUM_COLS; column++)
        {
            //Vertical (downwards) win condition for player 1.
            if((g[row][column] == 1) && (g[row + 1][column] == 1) && (g[row + 2][column] == 1) && (g[row + 3][column] == 1))
                return 1;

            //Vertical (downwards) win condition for player 2.
            if((g[row][column] == 2) && (g[row + 1][column] == 2) && (g[row + 2][column] == 2) && (g[row + 3][column] == 2))
                return 2;
        }
    }
    
    return 0;
}

int check_diagonal_L(int g[][NUM_COLS])
{
    //Only use appropriate spaces.
    //Starting coordinates for our search.
    int row = 0, column = 3;
    
    //Cycle through all relevant slots.
    for(row = 0; row < (NUM_ROWS - 3); row++)
    {
        for(column = 3; column < NUM_COLS; column++)
        {
            //Diagonal L win condition for player 1.
            if((g[row][column] == 1) && (g[row + 1][column - 1] == 1) && (g[row + 2][column - 2] == 1) && (g[row + 3][column - 3] == 1))
                return 1;

            //Diagonal L win condition for player 2.
            if((g[row][column] == 2) && (g[row + 1][column - 1] == 2) && (g[row + 2][column - 2] == 2) && (g[row + 3][column - 3] == 2))
                return 2;
        }
    }
    
    return 0;
}

int check_diagonal_R(int g[][NUM_COLS])
{
    //Only use appropriate spaces.
    //Starting coordinates for our search.
    int row = 0, column = 0;
    
    //Cycle through all relevant slots.
    for(row = 0; row < (NUM_ROWS - 3); row++)
    {
        for(column = 0; column < (NUM_COLS - 3); column++)
        {
            //Diagonal R win condition for player 1.
            if((g[row][column] == 1) && (g[row + 1][column + 1] == 1) && (g[row + 2][column + 2] == 1) && (g[row + 3][column + 3] == 1))
                return 1;

            //Diagonal R win condition for player 2.
            if((g[row][column] == 2) && (g[row + 1][column + 1] == 2) && (g[row + 2][column + 2] == 2) && (g[row + 3][column + 3] == 2))
                return 2;
        }
    }
    
    return 0;
}

int win_condition(int g[][NUM_COLS]){

    //Goes through all the check functions and condenses the process to get 1 return value.
    int check1, check2, check3, check4;

    check1 = check_diagonal_L(g);
    check2 = check_diagonal_R(g);
    check3 = check_horizontal(g);
    check4 = check_vertical(g);

    if((check1 == 1) || (check2 == 1) || (check3 == 1) || (check4 == 1))
        return 1;

    if((check1 == 2) || (check2 == 2) || (check3 == 2) || (check4 == 2))
        return 2;

    return 0;
}