#include "../../src/puzzle.h"

int main() {

  Puzzle test_puzzle;
  test_puzzle.create_grid(3,3);
  // Just a test... so the data doesn't matter
  test_puzzle.shift_row(0);
  test_puzzle.shift_row(1,true);
  test_puzzle.shift_row(2);
  test_puzzle.shift_row(2);
  test_puzzle.shift_col(0);
  test_puzzle.shift_col(1,true);
  test_puzzle.shift_col(2);
  test_puzzle.shift_col(2);
  test_puzzle.delete_grid();
  
  test_puzzle.create_grid(2,4);
  // Just a test... so the data doesn't matter
  test_puzzle.shift_row(0);
  test_puzzle.shift_row(0);
  test_puzzle.shift_row(1,true);
  test_puzzle.shift_row(1,true);
  test_puzzle.shift_col(0);
  test_puzzle.shift_col(1,true);
  test_puzzle.shift_col(2);
  test_puzzle.shift_col(2);
  test_puzzle.shift_col(3,true);
  test_puzzle.shift_col(3,true);
  test_puzzle.delete_grid();
  
  test_puzzle.create_grid(4,2);
  // Just a test... so the data doesn't matter
  test_puzzle.shift_row(0);
  test_puzzle.shift_row(1,true);
  test_puzzle.shift_row(2);
  test_puzzle.shift_row(2);
  test_puzzle.shift_row(3,true);
  test_puzzle.shift_row(3,true);
  test_puzzle.shift_col(0);
  test_puzzle.shift_col(0);
  test_puzzle.shift_col(1,true);
  test_puzzle.shift_col(1,true);
  test_puzzle.delete_grid();

}
