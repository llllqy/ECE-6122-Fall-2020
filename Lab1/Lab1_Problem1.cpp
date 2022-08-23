/*
Author:	Qingyuan Liu
Class: ECE6122
Last Date Modified: <17/9/2020>
Description:
The purpose of this file is to calculate the sum of prime numbers that belows the input number.
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool IsPrime(unsigned int a)
{
	for (unsigned int i = 2; i <= floor(sqrt(a)); i++)   
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	unsigned long a;
	a = atol(argv[1]);    //transfer argv[1] into unsigned long type

	unsigned long sum = 0; //initiate the sum to 0
	if (a == 0 || a == 1)  //For input values of 0 or 1 the sum is 0.
	{
		sum = 0;
	}
	else
	{
		for (unsigned long i = 2; i < a; i++)
		{
			if (IsPrime(i))    //if i is prime number,then add it to sum
			{
				sum += i;
			}
		}
	}
	
	ofstream file;               // out put the sum into output1.txt
	file.open("output1.txt" , ios::out);
	file << sum;
	file.close();
	
	return 0;
}