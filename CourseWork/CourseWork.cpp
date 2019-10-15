#include <fstream>
#include <iostream>

using namespace std;

void push_to_file(int* matrix,int length, int width, string filename) {
	ofstream myfile(filename, ios::app);
	if (myfile.is_open()) {
		for (int i = 0; i < length * width; i++) {
			if (i % width == length - 1) {
				myfile << *(matrix + i) << endl ;
			}
			else { 
				myfile << *(matrix + i) << " "; 
			}
		}
	}
	myfile.close();
}

int** pull_from_file(string filename, const int length, const int width) {
	ifstream myfile(filename);
	int **temp = new int*[length];
	for (int i = 0; i < length; i++) {
		temp[i] = new int[width];
	}
	cout << myfile.is_open();
	if (myfile.is_open()) {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				myfile >> temp[i][j];
				cout << temp[i][j];
			}
		}	
	}
	myfile.close();
	return temp;
}

int main() {
	int a[2][2] = {0,1,2,3};
	int b[3][3] = { 3,3,3,3,3,3,3,3,3 };
	int c[4][4] = { 4, 4, 4, 4, 4, 4, 4,4 ,4 ,4, 4,4, 4,4,4,4 };
	int** d;
	string filename = "example.txt";
	//push_to_file(*a, 2, 2, filename);
	//push_to_file(*b, 3, 3, filename);
	//push_to_file(*c, 4, 4, filename);
	d = pull_from_file(filename, 2, 2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << d[i][j];
		}
	}

	return 0;
}

