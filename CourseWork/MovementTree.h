#pragma once
#include "Puzzle.h"
class Tree
{
private:
	Tree* up;
	Tree* down;
	Tree* right;
	Tree* left;
	Puzzle* puzzle;
public:
	Tree();
	~Tree();
	void insert_movement();
	void print_tree();
	void terminate_tree();

};

