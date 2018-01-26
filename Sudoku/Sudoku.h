#pragma once

class Sudoku {
	
	int table[9][9];

public:

	Sudoku() {initSudoku(); };
	void printSudoku();
	void solveSudoku();

private:
	void initSudoku();
	void fillBoard();
	void deleteSomeFieldsFromBoard();

	bool isValid(int x, int y, int val);
	bool notInTheSameRow(int x, int val);
	bool notInTheSameColumn(int y, int val);
	bool notInTheSameSquare(int x, int y, int val);

};