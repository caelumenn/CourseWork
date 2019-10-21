#pragma once
#include "Puzzle.h"
class MovementTree
{
private:
	MovementTree* up_child;
	MovementTree* down_child;
	MovementTree* right_child;
	MovementTree* left_child;
	Puzzle* puzzle;
public:
	MovementTree(Puzzle* puzzle);
	~MovementTree();
	void insert_movement();
	void print_tree();
	void terminate_tree();

};

