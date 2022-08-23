/*
Author: <Qingyuan Liu>
Class: ECE6122
Last Date Modified : <15 / 10 / 2020>
Description :To solve the Another ant on the move problem
This file is the definition of the point grid
*/
#pragma once
#include <vector>
using namespace std;

class Points
{
public:
	Points();
	Points(int inSize);
	vector<vector<int>> points;
private:
	int size;
};