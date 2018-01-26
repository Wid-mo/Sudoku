#include <iostream>
#include "Sudoku.h"
#include <cstdlib>
#include <time.h>

using namespace std;

void Sudoku::initSudoku() {

	memset(this->table, 0, sizeof(this->table));
	srand(time(NULL));

	fillBoard();
	deleteSomeFieldsFromBoard();
}

void Sudoku::fillBoard() {
	for (int i = 0; i < 81; i++) {

		int x;
		int y;
		do {
			x = rand() % 9;
			y = rand() % 9;
		} while (table[y][x] != 0);
		

		for (int k = 1; k <= 9; k++) {

			if (isValid(x, y, k)) {
				this->table[y][x] = k;
				break;
			}
		}


	}
}

void Sudoku::deleteSomeFieldsFromBoard() {


}

void Sudoku::printSudoku() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (table[i][j] == 0)
				cout << ' ';
			else
				cout << table[i][j];

			cout << "  ";
			if (j % 3 == 2 && 9 - j != 1)
				cout << "|  ";
		}
			
		cout << endl;
		if (i % 3 == 2)
			cout << endl;
	}
}

void Sudoku::solveSudoku() {


}

bool Sudoku::isValid(int x, int y, int val) {

	return notInTheSameRow(y,val) && notInTheSameColumn(x,val) && notInTheSameSquare(x - x%3,y - y%3,val);
}

bool Sudoku::notInTheSameRow(int y, int val) {

	for (size_t i = 0; i < 9; i++) {
		if (table[y][i] == val)
			return false;
	}
	return true;
}

bool Sudoku::notInTheSameColumn(int x, int val) {

	for (size_t i = 0; i < 9; i++) {
		if (table[i][x] == val)
			return false;
	}
	return true;
}

bool Sudoku::notInTheSameSquare(int x, int y, int val) {

	for (size_t i = y; i < y+3; i++) {
		for (size_t j = x; j < x+3; j++) {

			if (table[i][j] == val)
				return false;
		}
	}
	return true;
}
