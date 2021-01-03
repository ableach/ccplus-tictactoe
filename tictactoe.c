/*
Author: A Bleach
Date: 03/01/2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clearScreen(void);
void drawGrid(int grid[]);
int captureMove(int player);
bool validMove(int playerMove);
void updateGrid(int grid[], int playerTurn, int playerMove);
int winnerFound(void);

int main() {
    int grid[10] = {0};
    int playerTurn = 1, playerMove = 0;
    bool validity;
    for ( int i=1; i<10; i++ ) {
        drawGrid(grid);
        do {
            playerMove = captureMove(playerTurn);
        } while ( validMove(playerMove) == false );
        updateGrid(grid,playerTurn,playerMove);
        if ( playerTurn == 1 )
            playerTurn = 2;
        else
            playerTurn = 1;
    }

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
capture player's move
*/
int captureMove(int player) {
    int playerMove;

    printf("\nPlayer %i - please choose where to play next: ",player);
    scanf("%i", &playerMove);

    return playerMove;
}

/*
check that a move is valid
1. is position valid (i.e. between 1 and 9)
2. is position available
*/
bool validMove(int playerMove) {
    bool validity = false;
    if (playerMove >= 1 && playerMove <= 9) {
        validity = true;
    }
    return validity;
}

void updateGrid(int grid[], int playerTurn, int playerMove) {
    grid[playerMove] = playerTurn;
}

/*
determine if a player has won
return the player id (1 or 2)
*/
int winnerFound(void) {
    return 0;
}