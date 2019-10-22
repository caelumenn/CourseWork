#include "Puzzle.h"

Puzzle::Puzzle():
	puzzle_x(0),puzzle_y(0),
	pos_x(0), pos_y(0),
	max(0),
	move_times(0),
	puzzle_blocks(nullptr),
	solution_file("solution_file.txt"),config_file("15-config.txt"),
	move(up),
	up_child(nullptr),
	down_child(nullptr),
	left_child(nullptr),
	right_child(nullptr)
	{}
Puzzle::Puzzle(const Puzzle& p) {
	this->puzzle_x = p.puzzle_x;
	this->puzzle_y = p.puzzle_y;
	this->pos_x = p.pos_x;
	this->pos_y = p.pos_y;
	this->move_times = p.move_times;
	this->max = p.max;
	this->set_puzzle_blocks(p.puzzle_blocks);
	this->solution_file = p.solution_file;
	this->config_file = p.config_file;
	this->move = p.move;
}
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
void Puzzle::set_pos_x(int pos_x) {
	this->pos_x = pos_x;
}
int Puzzle::get_pos_x() {
	return this->pos_x;
}
void Puzzle::set_pos_y(int pos_y){
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
	this->puzzle_blocks = new int* [this->puzzle_y];
	for (int i = 0; i < this->puzzle_y; i++) {
		this->puzzle_blocks[i] = new int[this->puzzle_x];
	}
	for (int i = 0; i < this->puzzle_y; i++) {
		for (int j = 0; j < this->puzzle_x; j++) {
			this->puzzle_blocks[i][j] = init[i][j];
		}
	}
}
int** Puzzle::get_puzzle_blocks() {
	return this->puzzle_blocks;
}
void Puzzle::set_move(move_towards move){
	this->move = move;
}
move_towards Puzzle::get_move() {
	return this->move;
}

bool repeat_check(int **arry, int x, int y, int check_num) {
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
		for (int j = 0; j < this->puzzle_x ; j++) {
			cout << "Please input a num from 1 to " << this->get_max() << endl;
			cin >> input;
			if (cin.fail()) {
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	}
	this->set_puzzle_blocks(puzzle);
}

void Puzzle::print_puzzle() {
	int** puzzle = this->get_puzzle_blocks();
	for (int i = 0; i < this->puzzle_y; i++) {
		for (int j = 0; j < this->puzzle_x; j++) {
			cout << puzzle[i][j] << "\t"; 
		}
		cout << endl;
	}
}

void Puzzle::random_generate() {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	vector<int> random;
	
	for (int i = 1; i <= max; i++) {
		random.push_back(i);
	}
	shuffle(random.begin(), random.end(), default_random_engine(seed));
	
	int** puzzle = new int* [this->puzzle_y];
	for (int i = 0; i < this->puzzle_y; i++) {
		puzzle[i] = new int[this->puzzle_x];
	}
	
	auto k = random.begin();
	for (int i = 0; i < this->puzzle_y; i++) {
		for (int j = 0; j < this->puzzle_x; j++) {
				if (i == this->puzzle_y - 1 && j == this->puzzle_x - 1) {
					puzzle[i][j] = 0;
				}
				else {
					puzzle[i][j] = *k;
					k++;
				}
			}
	}
	this->set_puzzle_blocks(puzzle);
}

int Puzzle::count_continuous_row() {
	int** puzzle = this->get_puzzle_blocks();
	int continuous_row = 0;
	for (int i = 0; i < this->get_puzzle_y() - 1; i++) {
		int count = 0;
		for (int j = 0; j < this->get_puzzle_x() - 1; j++) {
			if (puzzle[i][j + 1] - puzzle[i][j] == 1) {
				count++;
				if (count >= 3) {
					continuous_row++;
				}
			}
			else {
				count--;
			}
		}
	}
	return continuous_row;
}

int Puzzle::count_reverse_continuous_row() {
	int** puzzle = this->get_puzzle_blocks();
	int continuous_reverse_row = 0;
	for (int i = 0; i < this->get_puzzle_y() - 1; i++) {
		int count = 0;
		for (int j = 0; j < this->get_puzzle_x() - 1; j++) {
			if (puzzle[i][j + 1] - puzzle[i][j] == -1) {
				count++;
				if (count >= 3) {
					continuous_reverse_row++;
				}
			}
			else {
				count--;
			}
		}
	}
	return continuous_reverse_row;
}

int Puzzle::count_continuous_column() {
	int** puzzle = this->get_puzzle_blocks();
	int continuous_column = 0;
	for (int i = 0; i < this->get_puzzle_y() - 1; i++) {
		int count = 0;
		for (int j = 0; j < this->get_puzzle_x() - 1; j++) {
			if (puzzle[j+1][i] - puzzle[j][i] == 1) {
				count++;
				if (count >= 3) {
					continuous_column++;
				}
			}
			else {
				count--;
			}
		}
	}
	return continuous_column;
}

int Puzzle::count_reverse_continuous_column() {
	int** puzzle = this->get_puzzle_blocks();
	int continuous_reverse_column = 0;
	for (int i = 0; i < this->get_puzzle_y() - 1; i++) {
		int count = 0;
		for (int j = 0; j < this->get_puzzle_x() - 1; j++) {
			if (puzzle[j + 1][i] - puzzle[j][i] == -1) {
				count++;
				if (count >= 3) {
					continuous_reverse_column++;
				}
			}
			else {
				count--;
			}
		}
	}
	return continuous_reverse_column;
}

void Puzzle::move_up(){
	int** puzzle = this->get_puzzle_blocks();
	int temp = 0;
	pos_x = this->get_pos_x();
	pos_y = this->get_pos_y();
	int move_times = this->get_move_times();
	move_times++;

	temp = puzzle[pos_x - 1][pos_y];
	puzzle[pos_x - 1][pos_y] = puzzle[pos_x][pos_y];
	puzzle[pos_x][pos_y] = temp;

	this->set_pos_x(pos_x - 1);
	this->set_move_times(move_times);
	this->set_puzzle_blocks(puzzle);
}

void Puzzle::move_down() {
	int** puzzle = this->get_puzzle_blocks();
	int temp = 0;
	int pos_x = this->get_pos_x();
	int pos_y = this->get_pos_y();
	int move_times = this->get_move_times();
	move_times++;

	temp = puzzle[pos_x + 1][pos_y];
	puzzle[pos_x + 1][pos_y] = puzzle[pos_x][pos_y];
	puzzle[pos_x][pos_y] = temp;

	this->set_pos_x(pos_x + 1);
	this->set_move_times(move_times);
	this->set_puzzle_blocks(puzzle);
}

void Puzzle::move_left() {
	int** puzzle = this->get_puzzle_blocks();
	int temp = 0;
	int pos_x = this->get_pos_x();
	int pos_y = this->get_pos_y();
	int move_times = this->get_move_times();
	move_times++;

	temp = puzzle[pos_x][pos_y - 1];
	puzzle[pos_x][pos_y - 1] = puzzle[pos_x][pos_y];
	puzzle[pos_x][pos_y] = temp;

	this->set_pos_y(pos_y - 1);
	this->set_move_times(move_times);
	this->set_puzzle_blocks(puzzle);
}

void Puzzle::move_right() {
	int** puzzle = this->get_puzzle_blocks();
	int temp = 0;
	int pos_x = this->get_pos_x();
	int pos_y = this->get_pos_y();
	int move_times = this->get_move_times();
	move_times++;

	temp = puzzle[pos_x][pos_y + 1];
	puzzle[pos_x][pos_y + 1] = puzzle[pos_x][pos_y];
	puzzle[pos_x][pos_y] = temp;

	this->set_pos_y(pos_y + 1);
	this->set_move_times(move_times);
	this->set_puzzle_blocks(puzzle);
}