#include <stdio.h>
#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '-');
        }
        printf("\n");
    }
    printf("\n");
}
                                     
int isSafe(int board[N][N], int row, int col) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    // Check if there is a queen in the upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    // Check if there is a queen in the lower diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

int solveNQueensUtil(int board[N][N], int col) {
    if (col == N) {
        printSolution(board);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            count += solveNQueensUtil(board, col + 1);
            board[i][col] = 0; // Backtrack and try other positions
        }
    }

    return count;
}

int solveNQueens() {
    int board[N][N] = {{0}};

    int count = solveNQueensUtil(board, 0);
    return count;
}

int main() {
    int totalSolutions = solveNQueens();
    printf("Total solutions: %d\n", totalSolutions);

    return 0;
}

