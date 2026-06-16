#include "../../src/puzzle.h"

int main() {

  Puzzle test_puzzle;

  test_puzzle.create_grid(3,5);
  test_puzzle.delete_grid();
  test_puzzle.create_grid(5,3);
  test_puzzle.delete_grid();
  test_puzzle.create_grid(4,4);
  test_puzzle.delete_grid();

  return 0;
}
