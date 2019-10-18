#include "Puzzle.h"

int main() {
	int x = 4, y = 4;
	Puzzle* puzzle = new Puzzle();
	puzzle->set_puzzle_x(x);
	puzzle->set_puzzle_y(y);
	puzzle->set_max(15);
	puzzle->input_puzzle();
	puzzle->print_puzzle();
	return 0;
}