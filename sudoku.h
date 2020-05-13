
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class sudoku {
public:
	sudoku();
	void print();
	void solve();
	void readFile(char* name);
private:
	int grid[9][9] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
	{ 6, 0, 0, 1, 9, 5, 0, 0, 0 },
	{ 0, 9, 8, 0, 0, 0, 0, 6, 0 },
	{ 8, 0, 0, 0, 6, 0, 0, 0, 3 },
	{ 4, 0, 0, 8, 0, 3, 0, 0, 1 },
	{ 7, 0, 0, 0, 2, 0, 0, 0, 6 },
	{ 0, 6, 0, 0, 0, 0, 2, 8, 0 },

	{ 0, 0, 0, 4, 1, 9, 0, 0, 5 },	
	{ 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

	bool solveRecur(int r, int c);
	void printRecur(int r, int c);
	bool checkRow(int r, int c);
	bool checkCol(int r, int c);
	bool checkSquare(int r, int c);
};

sudoku::sudoku()
{

}

bool sudoku::checkRow(int r, int c) {
	int i = 0;
	int check = grid[r][c];

	while (i < 9){
		if (grid[r][i] == check && i != c){
			return false;
		}
		i=i+1;
	}
	return true;
}
bool sudoku::checkCol(int r, int c) {
	int i = 0;
	int check = grid[r][c];
	while (i < 9){
		if (grid[i][c] == check && i != r){
			return false;
		}
		i=i+1;
	}
	return true;
}
bool sudoku::checkSquare(int r, int c) {
	int check = grid[r][c];
	for (int i = r / 3 * 3; i < r / 3 * 3 + 3; i++)
	{
		for (int j = c / 3 * 3; j < c / 3 * 3 + 3; j++)
			if (grid[i][j] == check && r != i && c != j)
				return false;
	}
	return true;
}


void sudoku::printRecur(int r, int c) {
	if (r >= 9)
		return;
	if (c >= 9) {
		cout << endl;
		printRecur(r + 1, 0);
		return;
	}
	cout << grid[r][c] << " ";
	printRecur(r, c + 1);
}

void sudoku::print()
{
	printRecur(0, 0);
	cout << endl;
	cout << endl;
}
bool sudoku::solveRecur(int r, int c) {
	
	int number = 0;
	if (r >= 9) {
		return true;
	}
	if (c >= 9) {
		c = 0;
		r = r + 1;
	}
	if (grid[r][c] == 0) {
		while (true) {
			do {
				number = number + 1;
				grid[r][c] = number;
			} while (!checkCol(r, c) || !checkRow(r, c) || !checkSquare(r, c) && number <= 9);
			if (number > 9) {
				grid[r][c] = 0;
				return false;
			}
			if (solveRecur(r, c + 1)) {
				break;
			}
		}
	}
	return solveRecur(r, c + 1);
}

void sudoku::solve()
{
	if (solveRecur(0, 0)) {
		cout << "The solution is :" << endl;
		print();
	}
	else {
		cout << "no solution was determined" << endl;
	}
}

void sudoku::readFile(char * name)
{   
	ifstream file(name);

	if (file) {
		char number = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				file.get(number);
				grid[i][j] = number - '0';
			}
			file.get();
		}
	}
}