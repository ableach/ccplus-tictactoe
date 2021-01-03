#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void drawGrid(void);
void makeMove(int player, int position);
bool validateMove(void);
int checkForWin(void);

int main() {
    return 0;
}

/*
draw the grid
1. clear screen
2. header showing which player is which symbol
3. draw the grid
*/
void drawGrid(void) {
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