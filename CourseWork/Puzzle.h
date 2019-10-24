/*
Name:Wenshang Ying
Email:destinydy1213@gmail.com
*/

#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>      
#include <chrono> 
using namespace std;
enum  move_towards {up,down,left,right};
const int LEVEL = 16;
static vector<int**> puzzle_turn_set;


class Puzzle {
public:	
	Puzzle* up_child;
	Puzzle* down_child;
	Puzzle* right_child;
	Puzzle* left_child;
	int*** puzzle_config;
	string solution_file;
	string config_file;
	static int two;
	static int three;
	static int four;

	Puzzle();
	Puzzle(const Puzzle& p, move_towards move);
	~Puzzle();
	void init_puzzle_config();
	void set_puzzle_x(int& puzzle_x);
	int get_puzzle_x();
	void set_puzzle_y(int& puzzle_y);
	int get_puzzle_y();
	void set_pos_x(int pos_x);
	int get_pos_x();
	void set_pos_y(int pos_y);
	int get_pos_y();
	void set_config_num(int config_num);
	int get_config_num();
	void set_max(int max);
	int get_max();
	void set_move_times(int move_times);
	int get_move_times();
	void set_puzzle_blocks(int** init);
	void set_puzzle_blocks(int num);
	int** get_puzzle_blocks();
	void set_move(move_towards move);
	move_towards get_move();

	void input_puzzle();
	void random_generate();
	void print_puzzle();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	int count_continuous_row(int** puzzle, int partial);
	int count_continuous_column(int** puzzle, int partial);
	int count_reverse_continuous_row(int** puzzle, int partial);
	int count_reverse_continuous_column(int** puzzle, int partial);
	void push_to_file();
	void pull_from_file();
	void new_treenode(Puzzle& treenode);
	void delete_unvaild_tree(Puzzle& treenode);
	void travel_treenode(Puzzle *root);
	bool is_turn();
	bool check_turn_repeat();
	void push_turn_set();
	void count_result(int partial);
	void count_result();
	int count_result_partial(int** puzzle, int partial);
protected:
	int puzzle_x;
	int puzzle_y;
	int pos_x;
	int pos_y;
	int config_num;
	int move_times;
	int max;

	int** puzzle_blocks;
	move_towards move;
};