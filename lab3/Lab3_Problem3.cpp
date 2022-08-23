/*
Author: <Qingyuan Liu>
Class: ECE6122
Last Date Modified: <15/10/2020>
Description:
The purpose of this file is to use OpenMP to create a multi-threaded program 
that uses the fundamental theory and logic of the Monte Carlo Simulation technique
 to solve an optimization problem.
*/

#include <random>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <omp.h>
#include <thread>
using namespace std;

int main(int argc, char* argv [])
{
	int N = atoi(argv[1]);    //input the number of runs
	double max_Z = 0;
	int m = 0;
	double x1(0.0), x2(0.0), x3(0.0);

	unsigned long numThreads = thread::hardware_concurrency(); //the max number of threads dynamically
#pragma omp parallel num_threads(numThreads) //reduction(x1,x2,x3,max_Z)//num_threads(N)

	for (int j = 0; j < N; j++)
	{
		//generate 3 random numbers
		random_device rd;
		default_random_engine generator{ rd() };
		uniform_real_distribution<double> distribution1(0, 1.0);
		uniform_real_distribution<double> distribution2(0, 2.0);
		uniform_real_distribution<double> distribution3(2.0, 3.0);
		double x_1 = distribution1(generator);
		double x_2 = distribution2(generator);
		double x_3 = distribution3(generator);

		//calculate the equation
		double Z = 0;
		Z = (exp(x_1) + x_2) * (exp(x_1) + x_2) + 3 * (1.0 - x_3) * (1.0 - x_3);

		//mark the max value of Z and the corresponding j
		if (Z > max_Z)
		{
			max_Z = Z;
			x1 = x_1;
			x2 = x_2;
			x3 = x_3;
		}
	}

	//output the x1 x2 x3 for the max value of Z
	fstream outFile("Lab3Prob3.txt", fstream::out);
	//outFile << "max Z is : " << max_Z << endl;
	outFile << fixed << setprecision(15);
	outFile << "x1 : " << x1 << endl;
	outFile << "x2 : " << x2 << endl;
	outFile << "x3 : " << x3 << endl;
	//system("pause");
}