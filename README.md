<h1 align=center> C++ Matrix Puzzle Checkers </h1>
<h2 align=center> A CSC211: Computer Programming Assignment by Zachary Breene </h2>
<h4 align=center> Created at The University of Rhode Island, April 2021 </h4>
</n>
<h4 align=center> *NO AI WAS USED IN THE CREATION OF THIS PROJECT* </h4>

## Introduction
This repository contains two C++ command-line programs designed to process, simulate, and validate matrix-based grid puzzles. Both programs accept inputs via the terminal to either verify a completed 9x9 Sudoku board or simulate the movements of a 3x3 Sliding Puzzle to determine if a winning state was achieved.

---

## Implementation + Functions
### sudoku.cpp

This program acts as a rigorous validator for a completely filled 9x9 Sudoku board. </n>

&emsp; ***Recursive Grid Traversal***

* The `subsquare()` function serves as the core navigation logic, using recursion to iterate over all 81 squares of the 2D array matrix. It automatically shifts to the next row when it hits the edge boundary of the board.

&emsp; ***Block, Row, and Column Validation***

* For each square visited, the `blockCheck()` function isolates its 3x3 quadrant using modulo arithmetic and verifies that no duplicate integers exist. It then checks the remaining span of both its row and column for any duplicate numbers, failing the board immediately if a ruleset violation occurs.

### sliding_puzzle.cpp

This program simulates directional moves on a standard 3x3 Sliding Puzzle (where `0` represents the empty space) and evaluates the final board state. </n>

&emsp; ***Dynamic Matrix Simulation***

* The `create()` function takes in the starting state of the board. The program scans the initial grid to lock onto the `(x, y)` coordinates of the empty `0` tile. 

&emsp; ***Command Parsing & Position Swapping***

* A continuous input stream reads directional commands (`U`, `D`, `L`, `R`). The logic verifies array boundaries so the tile cannot move out of bounds, and then calls `change()` to pass values by reference and swap the integer positions inside the grid. 

&emsp; ***Win-State Verification***

* Once all moves are executed, the script flattens the 2D integer array down into a 1-dimensional format and cross-references it against a hardcoded target array `{1, 2, 3, 4, 5, 6, 7, 8, 0}` to output the final success or failure state[cite: 19].

---

## How To Run
To execute either program, you must compile the code using a C++ compiler like `g++`. Open your terminal, navigate to the directory, and compile the script (e.g., `g++ sudoku.cpp -o sudoku`). Run the compiled executable via the command line (`./sudoku`). 

*   **For Sudoku:** Input 81 space-separated integers representing the filled rows of the Sudoku board[cite: 18].
*   **For Sliding Puzzle:** Input 9 space-separated integers (1-8 and a 0) for the starting grid, followed by a sequence of directional characters (`U`, `D`, `L`, `R`) separated by spaces or newlines. Press `CTRL+D` (or the equivalent EOF command for your OS) to signal the end of your directional input and execute the check[cite: 19].

---

## Contribution
As I was the sole member of this project, I contributed to the whole of the project. This contribution is as follows:
* Development of 2D array matrix traversal logic
* Implementation of C++ reference variables for dynamic value swapping
* Creation of recursive validation algorithms
* Parsing of diverse sequence inputs via `std::cin`
