#include "puzzle.h"
#include <iostream>
using namespace std;

/*
Start by implementing puzzle.cpp functions

Once unit_tests are passing,
Use puzzle functions here to pass stdio_tests
*/

int main() {
  int puzzles;
  cin >> puzzles;
  Puzzle puzzle; // Use this puzzle object ONLY, don't create extras

  for (int k = 0; k < puzzles; k++) {
    //// YOUR CODE HERE ////
    // Read in rows, cols, moves
    // Allocate 2-D array
    // Read in symbols
    // Read in moves (solve puzzle)
    ////////////////////////

    int rows, cols, moves;
    cin >> rows >> cols >> moves;

    puzzle.create_grid(rows, cols);
    puzzle.fill_grid();

    for (int i = 0; i < moves; i++) {
      int index;
      char direction;
      cin >> index >> direction;
      index--;

      if (direction == 'R')
        puzzle.shift_row(index, true);
      else if (direction == 'L')
        puzzle.shift_row(index, false);
      else if (direction == 'D')
        puzzle.shift_col(index, true);
      else if (direction == 'U')
        puzzle.shift_col(index, false);
    }

    ////////////////////////
    // Print Solution
    puzzle.print_grid();

    if (k != puzzles - 1)
      cout << "\n";

    // De-allocate 2-D array

    puzzle.delete_grid();

    //// END YOUR CODE ////
  }

  return 0;
}
