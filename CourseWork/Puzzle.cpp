#include "Puzzle.h"
#include <fstream>
#include <iostream>

using namespace std;
Puzzle::Puzzle():
	puzzle_x(0),puzzle_y(0),
	pos_x(0), pos_y(0),
	max(0),
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
void Puzzle::set_max(int max) {
	this->max = max;
}
int Puzzle::get_max() {
	return this->max;
}
void Puzzle::set_move_times(int& move_times) {
	this->move_times = move_times;
}
int Puzzle::get_move_times() {
	return this->move_times;
}
void Puzzle::set_puzzle_blocks(int** init) {
	this->puzzle_blocks = init;
}
int** Puzzle::get_puzzle_blocks() {
	return this->puzzle_blocks;
}

bool input_check(int **arry, int x, int y, int check_num) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (check_num == arry[i][j]) {
				return true;
			}
		}
	}
	return false;
}

void Puzzle::input_puzzle() {
	int input = 0;
	int** puzzle = new int* [this->puzzle_y];
	for (int i = 0; i < this->puzzle_y; i++) {
		puzzle[i] = new int[this->puzzle_x];
	}
	for (int i = 0; i < this->puzzle_y; i++) {
		for (int j = 0; j < this->puzzle_x; j++) {
			cout << "Please input a num from 1 to " << this->get_max() << endl;
			cin >> input;
			if (cin.fail()) {
				cin >> ws;
				cout << "Wrong! Please input a num." << endl;
				j--;
			}
			else {
				if (input < 1 || input > this->get_max()) {
					cout << "Wrong num, please input a num from 1 to " << this->get_max() << endl;
					j--;
				}
				else if (repeat_check(puzzle, this->puzzle_x, this->puzzle_y, input)) {
					cout << "Already has a " << input << endl;
					j--;
				}
				else {
					puzzle[i][j] = input;
					system("CLS");
				}
			}
		}
		this->set_puzzle_blocks(puzzle);
	}
}

void Puzzle::print_puzzle() {
	int** puzzle = this->get_puzzle_blocks();
	for (int i = 0; i < this->puzzle_y; i++) {
		for (int j = 0; j < this->puzzle_x; j++) {
			cout << puzzle[i][j] << " "; 
		}
		cout << endl;
	}
}