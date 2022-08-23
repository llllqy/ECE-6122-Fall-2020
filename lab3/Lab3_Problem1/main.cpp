/*
Author: <Qingyuan Liu>
Class: ECE6122
Last Date Modified : <15 / 10 / 2020>
Description :Using threads to solve many sodoku problems in parallel
*/
#include <thread>
#include <fstream>
#include <iostream>
#include <vector>
#include "SudokuGrid.h"
#include <string>
#include <mutex>              // std::mutex, std::unique_lock

using namespace std;

void solveSudokuPuzzles();

fstream inFile;
fstream outFile("Lab3Prob1.txt", fstream::out);
mutex outFileMutex;
mutex inFileMutex;

int main(int argc, char* argv[])
{
	unsigned long numThreads = thread::hardware_concurrency(); //assign hardware thread to numThreads
	vector<SudokuGrid> vecGrids;
	vecGrids.resize(numThreads);

	inFile.open(argv[1]);//input file

	// start to spawn every thread
	vector<thread> threads;//create thread
	for (int i = 0; i < (numThreads - 1); ++i)
	{
		threads.push_back(thread(solveSudokuPuzzles));// add thread which 
	}
	for (auto& th : threads)    // synchronize the threads
	{
		th.join(); 
	}
}

void solveSudokuPuzzles()
{
	SudokuGrid grid;//create a Sudokugrid

	do {
		inFileMutex.lock();//lock infile by mutex
		inFile >> grid;
		inFileMutex.unlock();

		grid.solve();

		outFileMutex.lock();//lock outfile by mutex
		outFile << grid;//output
		outFileMutex.unlock();
	} while (!inFile.eof());//if no file, stop processing
}
