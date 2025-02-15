# Minesweeper Game in C

## Description

This is a simple command-line Minesweeper game written in C. The game lets you choose a board size (between 3 and 10) and a difficulty level ("easy", "normal", or "hard"). Bombs are randomly placed according to the chosen difficulty, and numbers indicate how many bombs are adjacent to each cell. The game features:

- Recursive reveal of empty cells.
- Colored terminal output for enhanced visualization.
- Background music (using `mpg123`) and sound effects (using `aplay`).
- Graceful exit via SIGINT signal handling.

## Requirements

- A Unix-like operating system (Linux recommended)
- GCC (or another C compiler)
- `mpg123` and `aplay` installed for audio playback
- Standard C libraries

## Compilation

Compile the program using GCC:

```bash
gcc -o minesweeper minesweeper.c
```
## Usage
Run the compiled executable:
```bash
./minesweeper
```
You will be prompted to enter:
1. **Board Size:** A number between 3 and 10.
2. **Difficulty:** One of easy, normal, or hard.

To exit the game at any time, enter -1 -1 when prompted for coordinates.

## Gameplay
- The board is displayed with colored row/column indices.
- Input the row (i) and column (j) coordinates to reveal a cell.
- Revealing a bomb (*) ends the game with a loss.
- Revealing a 0 automatically opens adjacent cells.
- The goal is to reveal all non-bomb cells.

## Authors
- [Erik Galstyan](https://github.com/Erik-Galstyan)
