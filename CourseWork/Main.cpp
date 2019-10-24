/*
Name:Wenshang Ying
Email:destinydy1213@gmail.com
*/

#include "Puzzle.h"

void write_result(Puzzle& puzzle) {
	ofstream myfile(puzzle.solution_file, ios::app);
	if (myfile.is_open()) {
		for (int i = 0; i < puzzle.get_config_num(); i++) {
			puzzle.set_puzzle_blocks(i);
			puzzle.new_tree(puzzle);
			puzzle.travel_tree(&puzzle);
			myfile << i + 1 << endl;
			puzzle.print_puzzle();
			puzzle.count_result(4);

			int two = 0;
			int three = 0;
			int four = 0;
			two = puzzle.count_result_partial(puzzle.get_puzzle_blocks(), 2);
			three = puzzle.count_result_partial(puzzle.get_puzzle_blocks(), 3);
			four = puzzle.count_result_partial(puzzle.get_puzzle_blocks(), 4);

			myfile << "(total for row&column, including reverse, in this configuration)" << endl;
			myfile << "2 = " << two << endl << "3 = " << three << endl << "4 = " << four << endl;
			puzzle.count_result();

		}
	}
	myfile.close();
	cout << "The result has written in the Solution-File." << endl;
	system("pause");
}
void Menu() {
	Puzzle *puzzle = new Puzzle();
	bool is_continue = true;
	while (is_continue) {
		puzzle_turn_set.clear();
		int choice = 0;
		cout << "<<<<<<<<<<<<<<<<<<<<<< n-Puzzle <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "Please input your choice:" << endl;
		cout << "1.Setting the Puzzle." << endl;
		cout << "2.input your Puzzle." << endl;
		cout << "3.Random generate your Puzzle config." << endl;
		cout << "4.Get configs from file." << endl;
		cout << "5.Count result." << endl;
		cout << "0.Exit." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			puzzle->puzzle_setting();
			break;
		case 2:
			puzzle->input_puzzle();
			break;
		case 3:
			puzzle->random_generate();
			break;
		case 4:
			puzzle->pull_from_file();
			break;
		case 5:
			write_result(*puzzle);
			break;
		case 0:
			is_continue = false;
			break;
		default:
			cout << "Please input a correct num." << endl;
			system("pause");
		}
		system("CLS");
	}
	delete puzzle;
	puzzle = nullptr;
}



int main() {
	Menu();
	return 0;
}