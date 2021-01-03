/*
Author: A Bleach
Date: 03/01/2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clearScreen(void);
void drawGrid(int grid[]);
void makeMove(int player, int position);
bool validateMove(void);
int checkForWin(void);

int main() {
    int grid[10] = {0};
    drawGrid(grid);
    return 0;
}

/*
draw the grid
1. clear screen
2. header showing which player is which symbol
3. draw the grid
*/
void drawGrid(int grid[]) {
    clearScreen();
    printf("Welcome to Tic Tac Toe!\n");
    printf("-----------------------\n\n");
    printf("Player 1: X\tPlayer 2: O\n\n");

    printf("--|---|--\n");
    for ( int i=1; i<10; i++ ) {
        if (grid[i] == 0) {
            printf("%i",i);    
        } else {
            ( grid[i] == 1 ) ? printf("X") : printf("O");
        }
        if ( i % 3 == 0 ) {
            printf("\n");
            printf("--|---|--\n");
        } else {
            printf(" | ");
        }
    }
    printf("\n");
}

/* 
clear screen 
couldn't get system("clear") et al to work
using ascci chars in place
*/
void clearScreen() {
    printf("\033[2J\033[H");
}

/*
store player's move
*/
void makeMove(int player, int position) {
}

/*
check that a move is valid
1. is position valid (i.e. between 1 and 9)
2. is position available
*/
bool validateMove(void) {
    return false;
}

/*
determine if a player has won
return the player id (1 or 2)
*/
int checkForWin(void) {
    return 0;
}