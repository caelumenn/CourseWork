#include <fstream>
#include <iostream>

using namespace std;

void push_to_file(int*** matrix,int& count, int& length, int& width, string filename) {
	ofstream myfile(filename, ios::app);
	if (myfile.is_open()) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < length; j++) {
				for (int k = 0; k < width; k++) {
					myfile << matrix[i][j][k];
					myfile << " ";
				}
				myfile << endl;
			}
			myfile << endl;
		}
	}
	myfile.close();
}

int*** pull_from_file(string filename, int& length, int& width) {
	ifstream myfile(filename);
	int count = 0;
	myfile >> count;
	int*** temp = new int** [count];
	for (int i = 0; i < count; i++) {
		temp[i] = new int*[length];
		for (int j = 0; j < length; j++) {
			temp[i][j] = new int[width];
		}
	}
	if (myfile.is_open()) {
		for(int i = 0; i< count;i++)
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < width; k++) {
				myfile >> temp[i][j][k];
				cout << temp[i][j][k];
			}
		}	
	}
	myfile.close();
	return temp;
}

/*int main() {
	int a[2][2] = {0,1,2,3};
	int b[3][3] = { 3,3,3,3,3,3,3,3,3 };
	int c[4][4] = { 4, 4, 4, 4, 4, 4, 4,4 ,4 ,4, 4,4, 4,4,4,4 };
	int*** d;
	string filename = "example.txt";
	push_to_file(*a, 2, 2, filename);
	push_to_file(*b, 3, 3, filename);
	push_to_file(*c, 4, 4, filename);
	d = pull_from_file(filename, 2, 2);
	push_to_file(d, 1, 2, 2, filename);
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				cout << d[i][j][k] << " ";
			}
		}
	}
	delete[] d;
	return 0;
}*/

