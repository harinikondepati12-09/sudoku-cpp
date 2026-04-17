# Sudoku Solver (C++)

A **C++ based Sudoku Solver and Game** that generates puzzles and allows users to solve them through a command-line interface.  
The system uses **backtracking and recursion** to efficiently solve Sudoku puzzles.

---

## Features

- Generates valid Sudoku puzzles
- Multiple difficulty levels (Easy, Medium, Hard)
- Solves Sudoku using backtracking algorithm
- Interactive user gameplay
- Validates user inputs
- Handles invalid inputs
- Exit option anytime

---

## Technologies Used

- C++
- Recursion
- Backtracking Algorithm
- 2D Arrays
- Randomization

---

## Project Structure

- `sudoku.cpp` → Main source code
- `sudoku_report.pdf` → Project documentation

---

## How to Run

```bash
g++ sudoku.cpp -o sudoku
./sudoku
```

---

## How to Play
- Choose difficulty level (Easy / Medium / Hard)
- Enter values in this format: ``` row column value ```
- Example: ```1 3 5```
- Enter ```0 0 0``` to exit the game

---

## Project Description
This project implements a Sudoku solver using backtracking, a recursive algorithm that tries all possible values for empty cells and backtracks when a conflict occurs.

---

The program also generates unique Sudoku puzzles using randomization and allows users to solve them interactively.

---

## Future Improvements
Add graphical interface (GUI)
Add timer and scoring system
Implement hint system
Save and load game

---

## Author
Harini K
