#pragma once
#include <iostream>
using namespace std;
class Puzzle {
public:
	Puzzle();
	~Puzzle();
	void set_puzzle_x(int& puzzle_x);
	int get_puzzle_x();
	void set_puzzle_y(int& puzzle_y);
	int get_puzzle_y();
	void set_pos_x(int& pos_x);
	int get_pos_x();
	void set_pos_y(int& pos_y);
	int get_pos_y();
	void set_max(int max);
	int get_max();
	void set_move_times(int& move_times);
	int get_move_times();
	void set_puzzle_blocks(int** init);
	int** get_puzzle_blocks();

	int count_continuous_row();
	int count_continuous_column();
	int count_reverse_continuous_row();
	int count_reverse_continuous_column();
	void print_puzzle();
	void input_puzzle();
	void random_generate();
	void push_to_file();
	void pull_from_file();
	void move();
protected:
	int puzzle_x;
	int puzzle_y;
	int pos_x;
	int pos_y;
	int move_times;
	int max;
	int** puzzle_blocks;
	string solution_file;
	string config_file;
	string move_towards;
	
};

