/*
Author: A Bleach
Date: 03/01/2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void takeTurn(int grid[], int playerTurn, int playerMove);
void clearScreen(void);
void drawGrid(int grid[]);
int captureMove(int player);
bool validMove(int grid[], int playerMove);
void updateGrid(int grid[], int playerTurn, int playerMove);
int winnerFound(int grid[]);
bool validInputRange(int playerMove);
bool vacantSquare(int grid[], int playerMove);

int main() {
    int grid[10] = {0};
    int playerTurn = 1, playerMove = 0, validMoveCount = 1, checkWinner = 0;

    while ( validMoveCount < 10 ) {
        takeTurn(grid, playerTurn, playerMove);
        checkWinner = winnerFound(grid);
        if ( checkWinner ) {
            drawGrid(grid);
            printf("Congratulations player %i. You have won!\n\n", checkWinner);
            break;
        }
        validMoveCount++;
        if ( playerTurn == 1 )
            playerTurn = 2;
        else
            playerTurn = 1;
    }

    if ( !checkWinner ) {
        printf("\nThe game was a draw.\n\n");
    }

    return 0;
}

void takeTurn(int grid[], int playerTurn, int playerMove)
{
    drawGrid(grid);
    do {
        playerMove = captureMove(playerTurn);
    } while ( validMove(grid, playerMove) == false );

    updateGrid(grid, playerTurn, playerMove);

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
using ANSI chars in place
*/
void clearScreen() {
    printf("\033[2J\033[H");
}

/*
capture player's move
*/
int captureMove(int player) {
    int playerMove;

    printf("\nPlayer %i - where do you wish to go? Please type a number from 1-9: ",player);
    scanf("%i", &playerMove);

    return playerMove;
}

/*
check that a move is valid
1. is position valid (i.e. between 1 and 9)
2. is position available
*/
bool validMove(int grid[], int playerMove) {
    bool validity = false;
    if (validInputRange(playerMove) && vacantSquare(grid, playerMove)) {
        validity = true;
    }
    return validity;
}

bool validInputRange(int playerMove) {
    bool validity = false;
    if (playerMove >= 1 && playerMove <= 9) {
        validity = true;
    }
    return validity;
}

bool vacantSquare(int grid[], int playerMove) {
    bool validity = false;
    if (grid[playerMove] == 0) {
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
// winning combinations:
// 1,2,3
// 4,5,6
// 7,8,9
// 1,4,7
// 2,5,8
// 3,6,9
// 1,5,9
// 3,5,7
*/
int winnerFound(int grid[]) {
    int winner = 0;
    if ( grid[1] == grid[2] && grid[2] == grid[3] ) {
        winner = grid[1];
    } else if ( grid[4] == grid[5] && grid[5] == grid[6] ) {
        winner = grid[4];
    } else if ( grid[7] == grid[8] && grid[8] == grid[9] ) {
        winner = grid[7];
    } else if ( grid[1] == grid[4] && grid[4] == grid[7] ) {
        winner = grid[1];
    } else if ( grid[2] == grid[5] && grid[5] == grid[8] ) {
        winner = grid[2];
    } else if ( grid[3] == grid[6] && grid[6] == grid[9] ) {
        winner = grid[3];
    } else if ( grid[1] == grid[5] && grid[5] == grid[9] ) {
        winner = grid[1];
    } else if ( grid[3] == grid[5] && grid[5] == grid[7] ) {
        winner = grid[3];
    }
    return winner;
}