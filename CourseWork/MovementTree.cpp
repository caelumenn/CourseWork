#include "MovementTree.h"

MovementTree::MovementTree(Puzzle* puzzle):
	up_child(nullptr),down_child(nullptr),
	right_child(nullptr),left_child(nullptr),
	puzzle(puzzle)
{}

void MovementTree::insert_movement() {
	move_towards move = this->puzzle->get_move();
	int pos_x = this->puzzle->get_pos_x();
	int pos_y = this->puzzle->get_pos_y();
	if (move == 0) {  //up, can't go down
		cout << "up, can't go down" << endl;
	}
	else if (move == 1) { //down, can't go up
		cout << "down, can't go up" << endl;
	}
	else if (move == 2) { //left, can't go right
		cout << "left, can't go right" << endl;
	}
	else if (move == 3) { //right, can't go left
		cout << "right, can't go left" << endl;
	}
	if (pos_x == 0) { // can't go up
		cout << "x = 0,can't go up" << endl;
	}
	if (pos_y == 0) { // can't go left 
		cout << "y = 0, can't go left" << endl;
	}
	if (pos_x == this->puzzle->get_puzzle_x() - 1) { // can't go down
		cout << "x = max, can't go down" << endl;
	}
	if (pos_y == this->puzzle->get_puzzle_y() - 1) { // can't go right
		cout << "y = max, can't go right" << endl;
	}	
}
