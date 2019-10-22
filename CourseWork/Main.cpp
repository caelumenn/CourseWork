#include "Puzzle.h"

int main() {
	int x = 4, y = 4;
	Puzzle puzzle;
	puzzle.set_puzzle_x(x);
	puzzle.set_puzzle_y(y);
	puzzle.set_pos_x(3);
	puzzle.set_pos_y(3);
	puzzle.set_max(20);
	puzzle.random_generate();
	puzzle.print_puzzle();
	cout << endl;
	puzzle.move_up();
	puzzle.print_puzzle();
	cout << endl;
	puzzle.up_child = new Puzzle(puzzle);
	cout << endl;
	puzzle.up_child->print_puzzle();
	cout << endl;
	puzzle.up_child->move_up();
	puzzle.up_child->print_puzzle();
	puzzle.up_child->random_generate();
	puzzle.up_child->print_puzzle();
	cout << endl;
	

	/*
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
	//move_towards move = move_towards::left;
	//puzzle.set_move(move);
	//MovementTree* tree = new MovementTree(puzzle);
	//tree->insert_movement();
	return 0;
}