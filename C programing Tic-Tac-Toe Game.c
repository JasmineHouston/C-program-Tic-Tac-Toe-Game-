#include <stdio.h>
#include <stdlib.h>

// Initialize board with numbers 1-9 gives easy player selection
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Function displays board
void displayBoard() {
    system("clear"); // "cls" for Windows
    printf("\n Tic-Tac-Toe \n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", board[6], board[7], board[8]);
}

// Function checks for winner
int checkWinner() {
    int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // Rows
        {0,3,6}, {1,4,7}, {2,5,8}, // Columns
        {0,4,8}, {2,4,6}           // Diagonals
    };
    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == board[winPatterns[i][1]] && 
            board[winPatterns[i][1]] == board[winPatterns[i][2]])
            return 1; // Found Winner 
    }
    return 0;
}

int main() {
    int player = 1, choice, moves = 0;
    char mark;

    while (moves < 9) {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d (%c), enter a position (1-9): ", player, mark);
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 9 || 
            board[choice-1] == 'X' || board[choice-1] == 'O') {
            printf("Invalid move! Try again.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        board[choice-1] = mark;
        moves++;

        if (checkWinner()) {
            displayBoard();
            printf("Player %d wins!\n", player);
            return 0;
        }
        player++;
    }
    displayBoard();
    printf("It's a draw!\n");
    return 0;
}
