#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char current_player;

// Initialize the board with empty spaces
void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    current_player = 'X'; // Start with player 'X'
}

// Print the current state of the board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Check if there is a winner
int check_winner() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}

// Check if the game is a draw
int check_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Switch to the other player
void switch_player() {
    current_player = (current_player == 'X') ? 'O' : 'X';
}

// Make a move on the board
void make_move(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move! Try again.\n");
        return;
    }
    board[row][col] = current_player;
    if (check_winner()) {
        print_board();
        printf("Player %c wins!\n", current_player);
        exit(0);
    } else if (check_draw()) {
        print_board();
        printf("It's a draw!\n");
        exit(0);
    }
    switch_player();
}

int main() {
    int row, col;
    initialize_board();

    while (1) {
        print_board();
        printf("Player %c, enter your move (row and column): ", current_player);
        scanf("%d %d", &row, &col);
        make_move(row - 1, col - 1);
    }

    return 0;
}
