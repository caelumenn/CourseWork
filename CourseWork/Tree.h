#pragma once
#include "Puzzle.h"
class MovementTree
{
private:
	MovementTree* up;
	MovementTree* down;
	MovementTree* right;
	MovementTree* left;
	Puzzle* puzzle;
public:
	MovementTree();
	~MovementTree();
	void insert_movement();
	void print_tree();
	void terminate_tree();

};

