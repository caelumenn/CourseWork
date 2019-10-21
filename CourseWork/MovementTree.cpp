#include "MovementTree.h"

MovementTree::MovementTree(Puzzle* puzzle):
	up_child(nullptr),down_child(nullptr),
	right_child(nullptr),left_child(nullptr),
	puzzle(puzzle)
{}

MovementTree::~MovementTree() {
}

void MovementTree::insert_movement() {
	this->up_child = new MovementTree(this->puzzle);
	this->down_child = new MovementTree(this->puzzle);
	this->left_child = new MovementTree(this->puzzle);
	this->right_child = new MovementTree(this->puzzle);

	move_towards move = this->puzzle->get_move();
	int pos_x = this->puzzle->get_pos_x();
	int pos_y = this->puzzle->get_pos_y();
	if (move == 0) {  //up, can't go down
		cout << "up, can't go down" << endl;
		delete this->down_child;
	}
	else if (move == 1) { //down, can't go up
		cout << "down, can't go up" << endl;
		delete this->up_child;
	}
	else if (move == 2) { //left, can't go right
		cout << "left, can't go right" << endl;
		delete this->right_child;
	}
	else if (move == 3) { //right, can't go left
		cout << "right, can't go left" << endl;
		delete this->left_child;
	}
	if (pos_x == 0) { // can't go up
		cout << "x = 0,can't go up" << endl;
		delete this->up_child;
	}
	if (pos_y == 0) { // can't go left 
		cout << "y = 0, can't go left" << endl;
		delete this->left_child;
	}
	if (pos_x == this->puzzle->get_puzzle_x() - 1) { // can't go down
		cout << "x = max, can't go down" << endl;
		delete this->down_child;
	}
	if (pos_y == this->puzzle->get_puzzle_y() - 1) { // can't go right
		cout << "y = max, can't go right" << endl;
		delete this->right_child;
	}	
}
