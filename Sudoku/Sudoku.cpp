#include <iostream>
#include "Sudoku.h"
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

void Sudoku::initSudoku() {

	memset(this->table, 0, sizeof(this->table));

	srand(time(NULL));
	vector<int> doOdwiedzenia;
	for (int i = 0; i < 81; i++)
		doOdwiedzenia.push_back(i);
	fillBoard(doOdwiedzenia);

	deleteSomeFieldsFromBoard();
}

void Sudoku::fillBoard(vector<int> doOdwiedzenia)
{
	
	vector<int> kolejnedostartu;
	kolejnedostartu = doOdwiedzenia;

	for (int i = 0; i < kolejnedostartu.size(); i++) {

		int losIndex = rand() % kolejnedostartu.size();
		int losIndexValue = kolejnedostartu[losIndex];

		kolejnedostartu.erase(kolejnedostartu.begin() + losIndex);
		
		int x = losIndexValue % 9;
		int y = losIndexValue / 9;
		for (int k = 1; k <= 9; k++) {

			if (isValid(x, y, k)) {
			
				doOdwiedzenia.erase(doOdwiedzenia.begin() + losIndex);
				this->table[y][x] = k;

				fillBoard(doOdwiedzenia);
				if (doOdwiedzenia.size() == 0)
					return;

				this->table[y][x] = 0;
				if (losIndex == doOdwiedzenia.size())
					doOdwiedzenia.push_back(losIndexValue);
				else
					doOdwiedzenia.insert(doOdwiedzenia.begin() + losIndex, losIndexValue);

				break;
			}
		}
	}
}

/*
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
*/

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

bool Sudoku::checkCorrectness()
{
	Sudoku s2;
	s2.copy();
	s2.solveSudoku();

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (this->table[i][j] != s2.table[i][j])
				return false;

	return true;
}

Sudoku Sudoku::copy()
{
	Sudoku temp;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			temp.table[i][j] = this->table[i][j];

	return temp;
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
