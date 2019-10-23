/*
Name:Wenshang Ying
Email:destinydy1213@gmail.com
*/

#include "Puzzle.h"

Puzzle::Puzzle():
	puzzle_x(0),puzzle_y(0),
	pos_x(0), pos_y(0),
	max(0),
	partial(0),
	config_num(0),
	move_times(0),
	puzzle_blocks(nullptr),
	solution_file("the Solution-File.txt"),config_file("the 15-File.txt"),
	move(up),
	up_child(nullptr),
	down_child(nullptr),
	left_child(nullptr),
	right_child(nullptr),
	puzzle_config(nullptr)
	{}
Puzzle::Puzzle(const Puzzle& p ,move_towards move) {
	this->puzzle_x = p.puzzle_x;
	this->puzzle_y = p.puzzle_y;
	this->pos_x = p.pos_x;
	this->pos_y = p.pos_y;
	this->max = p.max;
	this->move_times = p.move_times;
	this->set_puzzle_blocks(p.puzzle_blocks);
	this->solution_file = p.solution_file;
	this->config_file = p.config_file;
	this->move = move;
}
Puzzle::~Puzzle() {
	delete[] puzzle_blocks;
	delete[] puzzle_config;
}
void Puzzle::init_puzzle_config() {
	this->puzzle_config = new int** [this->config_num];
	for (int i = 0; i < this->config_num; i++) {
		this->puzzle_config[i] = new int* [this->puzzle_y];
		for (int j = 0; j < this->puzzle_y; j++) {
			this->puzzle_config[i][j] = new int[this->puzzle_x];
		}
	}
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
void Puzzle::set_config_num(int config_num) {
	this->config_num = config_num;
}
int Puzzle::get_config_num() {
	return this->config_num;
}
void Puzzle::set_max(int max) {
	this->max = max;
}
int Puzzle::get_max() {
	return this->max;
}
void Puzzle::set_partial(int partial) {
	this->partial = partial;
}
int Puzzle::get_partial() {
	return this->partial;
}
void Puzzle::set_move_times(int move_times) {
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
void Puzzle::set_puzzle_blocks(int num) {
	this->puzzle_blocks = new int* [this->puzzle_y];
	for (int i = 0; i < this->puzzle_y; i++) {
		this->puzzle_blocks[i] = new int[this->puzzle_x];
	}
	for (int i = 0; i < this->puzzle_y; i++) {
		for (int j = 0; j < this->puzzle_x; j++) {
			this->puzzle_blocks[i][j] = this->puzzle_config[num][i][j];
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
	int num = 0;
	cout << "How many 15-puzzle configs do you have:";
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong! Please input a num." << endl;
		cin >> num;
	}
	this->set_config_num(num);
	this->init_puzzle_config();
	for (int k = 0; k < num; k++) {
		for (int i = 0; i < this->puzzle_y; i++) {
			for (int j = 0; j < this->puzzle_x; j++) {
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
					else if (repeat_check(this->puzzle_config[k], this->puzzle_x, this->puzzle_y, input)) {
						cout << "Already has a " << input << endl;
						j--;
					}
					else {
						if (i == this->puzzle_y - 1 && j == this->puzzle_x - 1) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							this->puzzle_config[k][i][j] = 0;
							system("CLS");
							cout << "This config is completed, please start input next config." << endl;
						}
						else {
							this->puzzle_config[k][i][j] = input;
							system("CLS");
						}
					}
				}
			}
		}
	}
}

void Puzzle::print_puzzle() {
	int** puzzle = this->get_puzzle_blocks();
	for (int i = 0; i < this->puzzle_y; i++) {
		for (int j = 0; j < this->puzzle_x; j++) {
			cout << puzzle[i][j] << "\t"; 
		}
		cout << endl;
	}
	cout << endl;
}

void Puzzle::random_generate() {
	this->init_puzzle_config();
	vector<int> random;
	for (int i = 1; i <= max; i++) {
		random.push_back(i);
	}
	for (int num = 0; num < this->config_num; num++) {
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		shuffle(random.begin(), random.end(), default_random_engine(seed));
		auto iterator = random.begin();
		for (int i = 0; i < this->puzzle_y; i++) {
			for (int j = 0; j < this->puzzle_x; j++) {
				if (i == this->puzzle_y - 1 && j == this->puzzle_x - 1) {
					this->puzzle_config[num][i][j] = 0;
				}
				else {
					this->puzzle_config[num][i][j] = *iterator;
					iterator++;
				}
			}
		}
	}
}

int Puzzle::count_continuous_row() {
	int** puzzle = this->get_puzzle_blocks();
	int continuous_row = 0;
	for (int i = 0; i < this->get_puzzle_y() - 1; i++) {
		int count = 0;
		for (int j = 0; j < this->get_puzzle_x() - 1; j++) {
			if (puzzle[i][j + 1] - puzzle[i][j] == 1) {
				count++;
				if (count >= this->partial - 1) {
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
				if (count >= this->partial - 1) {
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
				if (count >= this->partial - 1) {
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
				if (count >= this->partial - 1) {
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

	temp = puzzle[this->pos_x - 1][this->pos_y];
	puzzle[this->pos_x - 1][this->pos_y] = puzzle[this->pos_x][this->pos_y];
	puzzle[this->pos_x][this->pos_y] = temp;
	this->set_pos_x(pos_x - 1);
	this->set_puzzle_blocks(puzzle);
	this->set_move(move_towards::up);
}

void Puzzle::move_down() {
	int** puzzle = this->get_puzzle_blocks();
	int temp = 0;
	temp = puzzle[this->pos_x + 1][this->pos_y];
	puzzle[this->pos_x + 1][this->pos_y] = puzzle[this->pos_x][this->pos_y];
	puzzle[this->pos_x][this->pos_y] = temp;
	this->set_pos_x(pos_x + 1);
	this->set_puzzle_blocks(puzzle);
	this->set_move(move_towards::down);
}

void Puzzle::move_left() {
	int** puzzle = this->get_puzzle_blocks();
	int temp = 0;
	temp = puzzle[this->pos_x][this->pos_y - 1];
	puzzle[this->pos_x][this->pos_y - 1] = puzzle[this->pos_x][this->pos_y];
	puzzle[this->pos_x][this->pos_y] = temp;
	this->set_pos_y(pos_y - 1);
	this->set_puzzle_blocks(puzzle);
	this->set_move(move_towards::left);
}

void Puzzle::move_right() {
	int** puzzle = this->get_puzzle_blocks();
	int temp = 0;
	temp = puzzle[this->pos_x][this->pos_y + 1];
	puzzle[this->pos_x][this->pos_y + 1] = puzzle[this->pos_x][this->pos_y];
	puzzle[this->pos_x][this->pos_y] = temp;
	this->set_pos_y(pos_y + 1);
	this->set_puzzle_blocks(puzzle);
	this->set_move(move_towards::right);
}

void Puzzle::push_to_file() {
	ofstream myfile(config_file);
	if (myfile.is_open()) {
		myfile << this->config_num << endl;
		for (int i = 0; i < this->config_num; i++) {
			for (int j = 0; j < this->get_puzzle_y(); j++) {
				for (int k = 0; k <this->get_puzzle_x(); k++) {
					myfile << this->puzzle_config[i][j][k];
					myfile << "\t";
				}
				myfile << endl;
			}
			myfile << endl;
		}
	}
	myfile.close();
}

void Puzzle::pull_from_file() {
	ifstream myfile(config_file);
	myfile >> this->config_num;
	this->init_puzzle_config();
	if (myfile.is_open()) {
		for (int i = 0; i < this->config_num; i++)
			for (int j = 0; j < this->puzzle_y; j++) {
				for (int k = 0; k < this->puzzle_x; k++) {
					myfile >> this->puzzle_config[i][j][k];
				}
			}
	}
	myfile.close();
}

void Puzzle::new_treenode(Puzzle& treenode) {
	if (this->move_times > LEVEL) {
		return;
	}
	this->move_times++;
	this->delete_unvaild_tree(*this);
	
	if (this->up_child != nullptr) {
		this->up_child->move_up();
		this->up_child->new_treenode(*this->up_child);
	}
	if (this->down_child != nullptr) {
		this->down_child->move_down();
		this->down_child->new_treenode(*this->down_child);
	}
	if (this->left_child != nullptr) {
		this->left_child->move_left();
		this->left_child->new_treenode(*this->left_child);
	}
	if (this->right_child != nullptr) {
		this->right_child->move_right();
		this->right_child->new_treenode(*this->right_child);
	}
}

void Puzzle::travel_treenode(Puzzle *root) {
	if (root->up_child != nullptr) {
		travel_treenode(root->up_child);
		root->up_child->print_puzzle();
	}
	if (root->down_child != nullptr) {
		travel_treenode(root->down_child);
		root->down_child->print_puzzle();
	}
	if (root->left_child != nullptr) {
		travel_treenode(root->left_child);
		root->left_child->print_puzzle();
	}
	if (root->right_child != nullptr) {
		travel_treenode(root->right_child);
		root->right_child->print_puzzle();
	}
}

void Puzzle::delete_unvaild_tree(Puzzle& treenode) {
	this->up_child = new Puzzle(treenode, move_towards::up);
	this->down_child = new Puzzle(treenode, move_towards::down);
	this->left_child = new Puzzle(treenode, move_towards::left);
	this->right_child = new Puzzle(treenode, move_towards::right);
	move_towards move = this->get_move();
	if (move == move_towards::up) {
		delete this->down_child;
		this->down_child = nullptr;
	}
	else if (move == move_towards::down) {
		delete this->up_child;
		this->up_child = nullptr;
	}
	else if (move == move_towards::left) {
		delete this->right_child;
		this->right_child = nullptr;
	}
	else if (move == move_towards::right) {
		delete this->left_child;
		this->left_child = nullptr;
	}
	if (this->pos_x == 0) {
		delete this->up_child;
		this->up_child = nullptr;
	}
	if (this->pos_y == 0) {
		delete this->left_child;
		this->left_child = nullptr;
	}
	if (this->pos_x == this->get_puzzle_x() - 1 && this->get_move() != move_towards::up) {
		delete this->down_child;
		this->down_child = nullptr;
	}
	if (this->pos_y == this->get_puzzle_y() - 1) {
		delete this->right_child;
		this->right_child = nullptr;
	}
}

bool Puzzle::is_turn() {

}