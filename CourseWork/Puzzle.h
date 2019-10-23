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
const int LEVEL = 4;
class Puzzle {
public:	
	Puzzle* up_child;
	Puzzle* down_child;
	Puzzle* right_child;
	Puzzle* left_child;
	int*** puzzle_config;

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
	void set_partial(int partial);
	int get_partial();
	void set_move_times(int& move_times);
	int get_move_times();
	void set_puzzle_blocks(int** init);
	void set_puzzle_blocks(int num);
	int** get_puzzle_blocks();
	void set_move(move_towards move);
	move_towards get_move();

	void input_puzzle();
	void random_generate();
	void print_puzzle();
	void move_up(Puzzle& p);
	void move_down(Puzzle& root);
	void move_left(Puzzle& root);
	void move_right(Puzzle& root);
	int count_continuous_row();
	int count_continuous_column();
	int count_reverse_continuous_row();
	int count_reverse_continuous_column();	
	void push_to_file();
	void pull_from_file();
	void write_result();
	void delete_unvaild_tree();
	void new_treenode(Puzzle& treenode);
	void travel_treenode(Puzzle *root);

protected:
	int puzzle_x;
	int puzzle_y;
	int pos_x;
	int pos_y;
	int config_num;
	int move_times;
	int max;
	int partial;

	int** puzzle_blocks;
	
	string solution_file;
	string config_file;
	move_towards move;
};