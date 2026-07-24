#include <iostream>

// Validates whether the number at coordinates (x, y) is valid according to Sudoku rules.
bool blockCheck(int sudokuSize[9][9], int x, int y)
{
    int i, j;
    // Uses modulo arithmetic to find the top-left corner index of the 3x3 subgrid.
    int column = y - y % 3;
    int row = x - x % 3;

    // Checks the 3x3 subgrid for duplicate values.
    for(i = row; i < row + 3; i++){
        for(j = column; j < column + 3; j++){
            if ((i != x || j != y) && sudokuSize[i][j] == sudokuSize[x][y]){
                return false;
            }
        }
    }
    
    // Checks the rest of the column for duplicate values.
    for(i = x + 1; i < 9; i++){
        if(sudokuSize[x][y] == sudokuSize[i][y]){
            return false;
        }
    }
    
    // Checks the rest of the row for duplicate values.
    for(i = y + 1; i < 9; i++){
        if(sudokuSize[x][y] == sudokuSize[x][i]){
            return false;
        }
    }
    return true; // The placement is valid.
}

// Recursively iterates through the 9x9 grid to check every cell.
bool subsquare(int sudokuSize[9][9], int x, int y) 
{
    // Base case: Reached the end of the board successfully.
    if (x == 9 - 1 && y == 9){
        return true;
    }
    // Wraps around to the next row when the end of a column is reached.
    if(y == 9){
        return subsquare(sudokuSize, x + 1, 0);
    }
    // Validates the current cell; if invalid, returns false immediately.
    if (!blockCheck(sudokuSize, x, y))
    {
        return false;
    }
    // Moves to the next cell in the row.
    return subsquare(sudokuSize, x, y + 1);
}

int main()
{
    int sudokuSize[9][9];
    int entry;
    
    // Populates the 9x9 grid from standard input.
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            std::cin >> entry;
            sudokuSize[i][j] = entry;
        }
    }

    // Initiates the recursive validation starting at index (0,0).
    if (subsquare(sudokuSize,0,0)){
        std::cout << "Solution is good!" << std::endl;
    }
    else{
        std::cout << "Wrong solution!" << std::endl;
    }

}