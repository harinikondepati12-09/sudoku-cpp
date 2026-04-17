#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

const int N = 9;

// Check if placing num is safe
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Backtracking Sudoku solver
bool solveSudoku(int grid[N][N]) {
    int row = -1, col = -1;
    bool emptyFound = false;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == 0) {
                row = r;
                col = c;
                emptyFound = true;
                break;
            }
        }
        if (emptyFound) break;
    }

    if (!emptyFound)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

// Print Sudoku grid
void printGrid(int grid[N][N]) {
    cout << "-------------------------\n";
    for (int r = 0; r < N; r++) {
        if (r % 3 == 0 && r != 0)
            cout << "-------------------------\n";
        for (int c = 0; c < N; c++) {
            if (c % 3 == 0) cout << "| ";
            if (grid[r][c] == 0) cout << ". ";
            else cout << grid[r][c] << " ";
        }
        cout << "|\n";
    }
    cout << "-------------------------\n";
}

// Remove cells based on level
void removeCells(int grid[N][N], string level) {
    int count;

    if (level == "easy") count = 30;
    else if (level == "medium") count = 40;
    else count = 50;

    while (count--) {
        int r = rand() % 9;
        int c = rand() % 9;
        grid[r][c] = 0;
    }
}

// Generate full Sudoku then remove cells
void generateSudoku(int puzzle[N][N], int solution[N][N], string level) {
    int grid[N][N] = {0};

    // Fill diagonal 3x3 boxes with random permutations
    for (int box = 0; box < 9; box += 3) {
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        random_shuffle(v.begin(), v.end());
        int idx = 0;

        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                grid[box + r][box + c] = v[idx++];
    }

    solveSudoku(grid);

    // Copy solution
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            solution[r][c] = grid[r][c];

    removeCells(grid, level);

    // Copy puzzle
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            puzzle[r][c] = grid[r][c];
}

// Check completion
bool checkWin(int puzzle[N][N], int solution[N][N]) {
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            if (puzzle[r][c] != solution[r][c])
                return false;
    return true;
}

int main() {
    srand(time(0));

    int puzzle[N][N], solution[N][N];
    string level;

    cout << "Select difficulty (easy / medium / hard): ";
    cin >> level;

    generateSudoku(puzzle, solution, level);

    while (true) {
        printGrid(puzzle);

        cout << "Enter row col value (1-9) or 0 0 0 to quit: ";
        int r, c, v;
        cin >> r >> c >> v;

        if (r == 0 && c == 0 && v == 0) {
            cout << "Game exited." << endl;
            break;
        }

        r--; c--;

        if (r < 0 || r > 8 || c < 0 || c > 8 || v < 1 || v > 9) {
            cout << "Invalid input! Try again." << endl;;
            continue;
        }

        if (solution[r][c] == v) {
            puzzle[r][c] = v;
        } else {
            cout << "Wrong value!" << endl;
        }

        if (checkWin(puzzle, solution)) {
            printGrid(puzzle);
            cout << "Congratulations! You solved the Sudoku!" << endl;
            break;
        }
    }

    return 0;
}