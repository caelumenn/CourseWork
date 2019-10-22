/*void MovementTree::insert_movement() {
	this->up_child = new MovementTree(puzzle);
	this->up_child->puzzle.move_up();
	this->up_child->puzzle.print_puzzle();
	this->puzzle.print_puzzle();
	this->down_child = new MovementTree(this->puzzle);
	this->left_child = new MovementTree(this->puzzle);
	this->right_child = new MovementTree(this->puzzle);

	move_towards move = this->puzzle.get_move();
	int pos_x = this->puzzle.get_pos_x();
	int pos_y = this->puzzle.get_pos_y();
	if (move == move_towards::up) //up, can't go down
		delete this->down_child;
	else if (move == move_towards::down) //down, can't go up
		delete this->up_child;
	else if (move == move_towards::left) //left, can't go right
		delete this->right_child;
	else if (move == move_towards::right) //right, can't go left
		delete this->left_child;
	if (pos_x == 0) //can't go up
		delete this->up_child;
	if (pos_y == 0) //can't go left 
		delete this->left_child;
	if (pos_x == this->puzzle.get_puzzle_x() - 1) //can't go down
		delete this->down_child;
	if (pos_y == this->puzzle.get_puzzle_y() - 1) //can't go right
		delete this->right_child;
}*/
