/*
Author:	Qingyuan Liu
Class: ECE6122
Last Date Modified: <16/9/2020>
Description:
The purpose of this file is to calculate the total times of reflection, after a laser entered a "white cell"
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int cal(double x1, double y1, double x2, double y2)
{
	double x, y, Sr, Si, So;
	for(unsigned int i = 1; ; i++)
	{
		Sr = -4.0 * (x2 / y2);           //slope of tangent line
		Si = (y2 - y1) / (x2 - x1);      //slope of incidence beam
		//calculate the slope the reflection light
		double x0, y0, xx, yy; 
		x0 = (y1 - y2 + Sr * x2 + x1 / Sr) / (Sr + 1.0/Sr);
		y0 = Sr * x0 -Sr * x2 + y2;
		xx = 2 * x0 - x1;   
		yy = 2 * y0 - y1;
		So = (y2 - yy) / (x2 - xx);      //slope of reflected beam

		//calculate the location of the new point
		x = (2 * So * (x2 * So - y2)) / (So * So + 4) - x2;
		y = So * x + y2 - x2 * So;

		if (fabs(x) < 0.01 && y > 0)//return the total number of reflection when the lignt go off the cell
		{
			return i;
		}
		else //starting calculate the next reflection point
		{
			x1 = x2;		y1 = y2;		x2 = x;		y2 = y;
		}
	}
}

int main()
{
	int num = cal(0, 10.1, 1.4, -9.6);   

	ofstream file;               // create a txt and output the number into output4.txt
	file.open("output4.txt", ios::out);
	file << num;
	file.close();

	return 0;
}