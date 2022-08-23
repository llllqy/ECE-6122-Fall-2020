/*
Author: <Qingyuan Liu>
Class: ECE6122
Last Date Modified : <15 / 10 / 2020>
Description :To solve the Another ant on the move problem
*/

#include <random>
#include <iomanip>
#include <fstream>
#include <omp.h>
#include <thread>
#include "Points.h"
#include <vector>
#include <getopt.h>

using namespace std;

bool getGoal(int size, Points newPoints);//, vector<vector<int>>& point);
bool getStuck(int size, int a, int b, vector<vector<int>>& points);

//generate random numbers
random_device rd;
default_random_engine generator{ rd() };
uniform_int_distribution<int> distribution1(1, 4);
int main(int argc, char* argv[])
{

	//input N g using getopt
	int N, g;
	int c = 0;
	while ((c = getopt(argc, argv, "N:g:")) != -1) {
		switch (c) 
		{
			case 'N':
				N = atoi(optarg);
				break;
			case 'g':
				g = atoi(optarg);
				break;
			default:
				break;
		}
	}

	int num_get = 0;	
#pragma omp  parallel for reduction(+:num_get)

	for (int i = 0; i < N; i++)
	{
		Points newPoints(g);
		if (getGoal(g, newPoints))
		{
			num_get++;
		}
	}

	//output the probability
	fstream outFile("Lab3Prob2.txt", fstream::out);
	double PP = (num_get + 0.0) / N;
	outFile << fixed << setprecision(7);
	outFile << "PP : " << PP << endl;
	
	return 0;
}


bool getGoal(int size, Points newPoints)
{
	int row = 1;    //row
	int col = 1;    //column
	do
	{
		int a = distribution1(generator);
		int rowSub = row - 1;
		int rowAdd = row + 1;
		int colSub = col - 1;
		int colAdd = col + 1;
		if (a == 1)      //up
		{
			if (newPoints.points[rowSub][col] == 1)
			{
				continue;
			}
			else
			{
				--row;
				newPoints.points[row][col] = 1;
			}
		}
		if (a == 2)        //down
		{
			if (newPoints.points[rowAdd][col] == 1)
			{
				continue;
			}
			else
			{
				++row;
				newPoints.points[row][col] = 1;
			}
		}
		if (a == 3)           //left
		{
			if (newPoints.points[row][colSub] == 1)
			{
				continue;
			}
			else
			{
				--col;
				newPoints.points[row][col] = 1;
			}
		}
		if (a == 4)   //right
		{
			if (newPoints.points[row][colAdd] == 1)
			{
				continue;
			}
			else
			{
				++col;
				newPoints.points[row][col] = 1;
			}
		}
		if ((row == size) && (col == size))    //if the ant gets the end point(size,size)
		{
			return 1;
		}
		if (getStuck(size, row, col, newPoints.points))      //if the ant get stuck so that the ant failed
		{
			return 0;
		}
	} while (true);
}

bool getStuck(int size, int row, int col, vector<vector<int>>& points)
{
	int rowSub = row - 1;
	int rowAdd = row + 1;
	int colSub = col - 1;
	int colAdd = col + 1;

	if (points[rowSub][col] != 1)
	{
		return 0;
	}

	if (points[rowAdd][col] != 1)
	{
		return 0;
	}
	if (points[row][colAdd] != 1)
	{
		return 0;
	}

	if (points[row][colSub] != 1)
	{
		return 0;
	}

	else         //can't go anywhere for 4 directions
	{
		return 1;
	}
}
