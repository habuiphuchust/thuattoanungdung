#include <iostream>
using namespace std;

const int N = 9;

bool is_safe(int board[N][N], int row, int col, int num) {
    // Check if 'num' is not present in the current row and column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not present in the current 3x3 subgrid
    int start_row = 3 * (row / 3);
    int start_col = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[start_row + i][start_col + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool find_empty_cell(int board[N][N], int& row, int& col) {
    // Find the next empty cell (cell with value 0) in the board
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

int count_sudoku_solutions(int board[N][N]) {
    int row, col;
    if (!find_empty_cell(board, row, col)) {
        // If there are no empty cells, a solution is found
        return 1;
    }

    int total_solutions = 0;
    for (int num = 1; num <= 9; num++) {
        if (is_safe(board, row, col, num)) {
            // Try placing 'num' in the current cell
            board[row][col] = num;
            // Recursively check for solutions with the updated board
            total_solutions += count_sudoku_solutions(board);
            // Backtrack and remove 'num' from the current cell
            board[row][col] = 0;
        }
    }

    return total_solutions;
}

int main() {
    int partial_sudoku_board[N][N];
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		cin >> partial_sudoku_board[i][j];
		}
	}

    int num_solutions = count_sudoku_solutions(partial_sudoku_board);
    cout << num_solutions << endl;

    return 0;
}
