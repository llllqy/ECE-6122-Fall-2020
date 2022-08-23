/*
Author: <Qingyuan Liu>
Class: ECE6122
Last Date Modified : <13 / 10 / 2020>
Description :Using threads to solve many sodoku problems in parallel
this file is the definition of the Class
The solution for solving sokudo is based on the link https://www.tutorialspoint.com/sudoku-solver-in-cplusplus
*/

#pragma once
using namespace std;

class SudokuGrid
{
public:
    SudokuGrid();
    SudokuGrid(string stringName);  
    bool isPresentInCol(int col, int num);
    bool isPresentInRow(int row, int num);
    bool isPresentInBox(int boxStartRow, int boxStartCol, int num);
    bool findEmptyPlace(int& row, int& col);
    bool isValidPlace(int row, int col, int num);
    bool solveSudoku();
    void solve();
    friend fstream& operator>>(fstream& os, SudokuGrid& gridIn);
    friend fstream& operator<<(fstream& os, const SudokuGrid& gridIn);

private:
    string m_strGridName;   //name of the grid
    unsigned char gridElement[9][9]; //elements of the grid
};