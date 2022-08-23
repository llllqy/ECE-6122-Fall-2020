/*
Author: <Qingyuan Liu>
Class: ECE6122
Last Date Modified : <15 / 10 / 2020>
Description :To solve the Another ant on the move problem
This file is the definition of the point grid
*/
#include "Points.h"

Points::Points()
{
	size = 0;
}

//initiate the points grid
Points::Points(int inSize)
{
	size = inSize;
	int bigSize = size + 2;
	points.resize(bigSize);
	for (int i = 0; i < bigSize; i++)
	{
		points[i].resize(bigSize);
	}
	//initiate every point
	for (int i = 0; i <= size + 1; i++)
	{
		for (int j = 0; j <= size + 1; j++)
		{
			points[i][j] = 1;           //every point has not been visited
		}
	}
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			points[i][j] = 0;           //every point has not been visited
		}
	}
	
	//initiate the start point
	points[1][1] = 1;                //(1,1) has been visited
}
