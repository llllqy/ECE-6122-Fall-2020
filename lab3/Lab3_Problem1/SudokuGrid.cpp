/* 
Author: <Qingyuan Liu>
Class: ECE6122
Last Date Modified : <13 / 10 / 2020>
Description :Using threads to solve many sodoku problems in parallel
The solution for solving sokudo is based on the link https://www.tutorialspoint.com/sudoku-solver-in-cplusplus
*/

#include <fstream>
#include <iostream>
#include "SudokuGrid.h"
#include <string>
using namespace std;

// class initialization
SudokuGrid::SudokuGrid()
{
	m_strGridName = "nullGrid";
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gridElement[i][j] = 0;
		}
	}
}

// class constructor
SudokuGrid::SudokuGrid(string stringName)
{
	m_strGridName = stringName;
}

bool SudokuGrid::isPresentInCol(int col, int num)
{ //check whether num is present in col or not
	for (int row = 0; row < 9; row++)
		if (gridElement[row][col] - '0' == num)
			return true;
	return false;
}

bool SudokuGrid::isPresentInRow(int row, int num)
{ //check whether num is present in row or not
	for (int col = 0; col < 9; col++)
	{
		int a = gridElement[row][col] - '0';
		if (a == num)
			return true;
	}
	return false;
}

bool SudokuGrid::isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
	//check whether num is present in 3x3 box or not
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (gridElement[row + boxStartRow][col + boxStartCol] - '0' == num)
				return true;
	return false;
}

bool SudokuGrid::findEmptyPlace(int& row, int& col)
{ //get empty location and update row and column
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (gridElement[row][col] == '0') //marked with 0 is empty
				return true;
		}
	}
	return false;
}

bool SudokuGrid::isValidPlace(int row, int col, int num) {
	//when item not found in col, row and current 3x3 box
	return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3,	col - col % 3, num);
}

bool SudokuGrid::solveSudoku() {
	int row, col;
	if (!findEmptyPlace(row, col))
		return true; //when all places are filled
	for (int num = 1; num <= 9; num++)
	{ //valid numbers are 1 - 9
		if (isValidPlace(row, col, num))
		{ //check validation, if yes, put the number in the grid
			gridElement[row][col] = num + '0';
			if (solveSudoku()) //recursively go for other rooms in the grid
				return true;
			gridElement[row][col] = '0'; //turn to unassigned space when conditions are not satisfied
		}
	}
	return false;
}

void SudokuGrid::solve()       //solution
{
	if (solveSudoku() != true)cout << "No solution exists";	
}

fstream& operator>>(fstream& os, SudokuGrid& gridIn)
{
	getline(os, gridIn.m_strGridName);     //input the No. and name of the grid
	for (long i = 0; i < 9; i++)
	{
		for (long j = 0; j < 9; j++)
		{
			os >> gridIn.gridElement[i][j] ;
		}
	}
	os.get();      //Skip the blank key and enter 
	return os;
}

fstream& operator<<(fstream& os, const SudokuGrid& gridIn)
{
	os << gridIn.m_strGridName.c_str() << endl;
	for (long i = 0; i < 9; i++)
	{
		for (long j = 0; j < 9; j++)
		{
			os << gridIn.gridElement[i][j];
		}
		os << endl;
	}
	return os;
}
