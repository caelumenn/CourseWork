/*
Name:Wenshang Ying
Email:destinydy1213@gmail.com
*/

#include "Puzzle.h"

Puzzle puzzle_setting() {
	Puzzle puzzle;
	return puzzle;
}

void Menu() {
	Puzzle puzzle;
	bool is_continue = true;
	while (is_continue) {
		puzzle_turn_set.clear();
		int choice = 0;
		cout << "<<<<<<<<<<<<<<<<<<<<<< n-Puzzle <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "Please input your choice:" << endl;
		cout << "1.Setting the Puzzle." << endl;
		cout << "2.input your Puzzle." << endl;
		cout << "3.Random generate your Puzzle config." << endl;
		cout << "4.Count result." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			puzzle = puzzle_setting();
			break;
		case 2:
			puzzle.input_puzzle();
			break;
		case 3:
			puzzle.random_generate();
			break;
		case 4:
			break;
		default:
			cout << "Please input the correct num." << endl;
		}
		cout << "Do you want to continue? y/n" << endl;
		char answer;
		cin >> answer;
		if (answer != 'y' && answer != 'Y') {
			is_continue = false;
		}
	}
}

int main() {
	Puzzle root;
	root.set_config_num(3);
	root.set_max(15);
	root.random_generate();
	ofstream myfile(root.solution_file, ios::app);
	if (myfile.is_open()) {
		for (int i = 0; i < root.get_config_num(); i++) {

			root.set_puzzle_blocks(i);
			root.new_treenode(root);
			root.travel_treenode(&root);
			myfile << i + 1 << endl;
			root.print_puzzle();
			root.count_result(4);

			int two;
			int three;
			int four;
			two = root.count_result_partial(root.get_puzzle_blocks(), 2);
			three = root.count_result_partial(root.get_puzzle_blocks(), 3);
			four = root.count_result_partial(root.get_puzzle_blocks(), 4);

			myfile << "(total for row&column, including reverse, in this configuration)" << endl;
			myfile << "2 = " << two << endl << "3 = " << three << endl << "4 = " << four << endl;
			root.count_result();

		}	
	}
	myfile.close();
	return 0;
}