#include "Puzzle.h"
#include "MovementTree.h"

int main() {
	int x = 4, y = 4;
	int ac = 3, bc = 3;
	Puzzle puzzle;
	puzzle.set_puzzle_x(x);
	puzzle.set_puzzle_y(y);
	puzzle.set_pos_x(ac);
	puzzle.set_pos_y(bc);
	puzzle.set_max(16);
	puzzle.input_puzzle();
	/*
	puzzle->print_puzzle();
	int a = puzzle->count_continuous_row();
	int b = puzzle->count_reverse_continuous_row();
	int c = puzzle->count_continuous_column();
	int d = puzzle->count_reverse_continuous_column();
	cout << a << endl << b << endl << c << endl << d;
	puzzle->move_up();
	puzzle->print_puzzle();
	puzzle->move_left();
	puzzle->print_puzzle();
	puzzle->move_down();
	puzzle->print_puzzle();
	puzzle->move_right();
	puzzle->print_puzzle();
	cout << puzzle->get_move_times();*/
	move_towards move = move_towards::left;
	puzzle.set_move(move);
	MovementTree* tree = new MovementTree(puzzle);
	tree->insert_movement();
	return 0;
}