#include "Puzzle.h"
#include <fstream>
Puzzle::Puzzle():
	puzzle_x(0),puzzle_y(0),
	pos_x(0), pos_y(0),
	move_times(0),
	puzzle_blocks(nullptr),
	solution_file("solution_file.txt"),config_file("15-config.txt"){}
Puzzle::~Puzzle() {
	delete[] puzzle_blocks;
}
void Puzzle::set_puzzle_x(int& puzzle_x) {
	this->puzzle_x = puzzle_x;
}
int Puzzle::get_puzzle_x() {
	return this->puzzle_x;
}
void Puzzle::set_puzzle_y(int& puzzle_y) {
	this->puzzle_y = puzzle_y;
}
int Puzzle::get_puzzle_y() {
	return this->puzzle_y;
}
void Puzzle::set_pos_x(int& pos_x) {
	this->pos_x = pos_x;
}
int Puzzle::get_pos_x() {
	return this->pos_x;
}
void Puzzle::set_pos_y(int& pos_y){
	this->pos_y = pos_y;
}
int Puzzle::get_pos_y() {
	return this->pos_y;
}
void Puzzle::set_move_times(int& move_times) {
	this->move_times = move_times;
}
int Puzzle::get_move_times() {
	return this->move_times;
}
void Puzzle::init_puzzle_blocks(int** init) {
	this->puzzle_blocks = init;
}
int** Puzzle::get_puzzle_blocks() {
	return this->puzzle_blocks;
}