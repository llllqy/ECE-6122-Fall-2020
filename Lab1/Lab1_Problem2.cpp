/*
Author: Qingyuan Liu
Class: ECE6122
Last Date Modified: <16/9/2020>
Description:
The purpose of this file is to get the sum of Collatz sequence.
*/

#include<iostream>
#include<fstream>

using namespace std;

int main( int argc, char* argv[])
{
	unsigned long i, j, sum;  
	i = atol(argv[1]);  //transfer argv[1] into unsigned long type
	sum = i;          //initiate sum into the input number

	for (unsigned long ii = 1; i != 1; ii++)  //the loop stops when i is 1
	{
		if (i % 2 == 0)  //if i is even the next number is i/2
		{
			i = i / 2;
		}
		else            //if  i is odd the next number is 3i+1
		{
			i = 3 * i + 1;
		}
		sum += i;
	};
	ofstream file;               // put the sum in outpou2.txt
	file.open("output2.txt", ios::out);
	file << sum;
	file.close();

	return 0;
}