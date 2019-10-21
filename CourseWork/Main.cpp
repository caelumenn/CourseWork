#include "Puzzle.h"
#include "MovementTree.h"

int main() {
	int x = 4, y = 4;
	Puzzle* puzzle = new Puzzle();
	puzzle->set_puzzle_x(x);
	puzzle->set_puzzle_y(y);
	move_towards move = move_towards::left;
	puzzle->set_move(move);
	MovementTree* tree = new MovementTree(puzzle);
	tree->insert_movement();
	return 0;
}