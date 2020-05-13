
using namespace std;

#include "sudoku.h"

int main()
{ 
	sudoku mypuzzle;
	mypuzzle.readFile("puzzle0.txt");
	mypuzzle.print();
	mypuzzle.solve();
	mypuzzle.print();

}
