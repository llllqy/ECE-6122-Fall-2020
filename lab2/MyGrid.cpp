/*
Author: <Qingyuan Liu>
Class: ECE4122 or ECE6122
Last Date Modified: <2/10/2020>
Description:
	Constructe a class called MyGrid that has a member variable gridElements
that is a dynamic two-dimensional array of elements (type long) of m rows by n columns.
*/

#include <fstream>
#include <iostream>
#include <vector>
#include "MyGrid.h"
using namespace std;

// return the result whether we have successfully load the Grid from input file
bool MyGrid::loadGridFromFile(const string& filename)           
{
	ifstream in(filename);
	if(!in.good())
	{ 
		return false;
	}
	while (in.good())//if(in.good())
	{
		in >> myX >> myY >> rows >> cols;

		//initiate the vector
		for (long i = 0; i < rows; i++)                     
		{
			gridElements.push_back(* new vector<long>());
			for (long j = 0; j < cols; j++) 
			{
				gridElements.at(i).push_back(0);
			}
		}
		//load every element from file
		for (long i = 0; i < rows; i++)
		{
			for (long j = 0; j < cols; j++)
			{
				in >> gridElements[i][j];
			}
		}
	}
	return true;
}

//set every elements of grid to 0
void MyGrid::zeroOutGrid()   
{
	for (long i = 0; i < rows; i++)
	{
		for (long j = 0; j < cols; j++)
		{
			gridElements[i][j] = 0;
		}
	}
}

long MyGrid::getNumRows() const
{
	return rows;
}

long MyGrid::getNumCols() const
{
	return cols;
}

//add two grids
MyGrid MyGrid::operator+(MyGrid const &rhs) const    
{ 
	//if one grid is just constructed with no element, return another grid 
	MyGrid new1Grid(*this);
	if (this->cols == 0 || this->rows == 0)     
	{
		new1Grid.myX = rhs.myX;
		new1Grid.myY = rhs.myY;
		new1Grid.rows= rhs.rows;
		new1Grid.cols = rhs.cols;
		new1Grid.gridElements = rhs.gridElements;
		return new1Grid;
	}

	//add two normal (with elements) grids
	MyGrid newGrid;
	newGrid.myX = (this->myX < rhs.myX) ? this->myX : rhs.myX;          //new myX is the less one
	newGrid.myY = (this->myY > rhs.myY) ? this->myY : rhs.myY;          //new myY is the bigger one
	newGrid.rows = max( max( rhs.rows, (this->rows + rhs.myY - this->myY) ), this->rows );     //new rows is the max of the three conditions
	long nr = newGrid.rows;
	newGrid.cols = max( max( (rhs.cols + rhs.myX - this->myX), this->cols ), rhs.cols );      //new columns is the max of the three conditions
	long nc = newGrid.cols;

	//enlarge (resize)the original vector,put the origin elements in new location
	vector<vector<long>> vec1(nr, vector<long>(nc, 0));
	long m = 0;
	for (long i = (newGrid.myY - this->myY); i < (newGrid.myY - this->myY + this->rows); i++)
	{
		long n = 0;
		for (long j = (this->myX - newGrid.myX); j < (this->myX - newGrid.myX + this->cols); j++)
		{ 
			vec1[i][j] = this->gridElements[m][n];
			n++;
		}
		m++;
	}

	vector<vector<long>> vec2(nr, vector<long>(nc, 0));
	long p = 0;
	for (long i = (newGrid.myY - rhs.myY); i < (newGrid.myY - rhs.myY + rhs.rows); i++)
	{
		long q = 0;
		for (long j = ( rhs.myX - newGrid.myX ); j < (rhs.myX - newGrid.myX + rhs.cols); j++)
		{
			vec2[i][j] = rhs.gridElements[p][q];
			q++;
		}
		p++;
	}

	//add the two enlarged grids then get the result
	for (long i = 0; i < nr; i++)
	{
		newGrid.gridElements.push_back(*new vector<long>());
		for (long j = 0; j < nc; j++)
		{
			newGrid.gridElements.at(i).push_back(vec1[i][j] + vec2[i][j]);
		}
	}
	return newGrid;
}

MyGrid MyGrid::operator-(MyGrid const &rhs) const    //gird1 - grid2
{
	MyGrid newGrid(*this);
	newGrid = newGrid + (-rhs);
	return newGrid;
}

MyGrid MyGrid::operator+(long const &inLong) const    
{
	MyGrid newGrid(*this);
	vector<vector<long>> nGrid(this->rows, vector<long>(this->cols, 0));
	for (long i = 0; i < this->rows; ++i)
	{
		for (long j = 0; j < this->cols; ++j)
		{
			nGrid[i][j] = this->gridElements[i][j] + inLong;
		}
	}
	newGrid.gridElements = nGrid;
	return newGrid;
}

MyGrid& MyGrid::operator+=(MyGrid const& rhs)            //a += b
{
	//MyGrid tmp = *this;
	*this = *this + rhs;
	return *this;
}

MyGrid& MyGrid::operator++()                      //prefix++
{
	for (long i = 0; i < rows; i++)
	{
		for (long j = 0; j < cols; j++)
		{
			gridElements[i][j] ++;
		}
	}
	return *this;
}

MyGrid MyGrid::operator++(int)                   //postfix++
{
	MyGrid temp = *this;
	++(*this);
	return temp;
}

MyGrid& MyGrid::operator--()                        //prefix--
{
	for (long i = 0; i < rows; i++)
	{
		for (long j = 0; j < cols; j++)
		{
			gridElements[i][j] --;
		}
	}
	return *this;	
}

MyGrid MyGrid::operator--(int)                       //postfix--
{
	MyGrid temp = *this;
	--(*this);
	return temp;
}

MyGrid MyGrid::operator-() const                   //negation
{
	MyGrid tmp1Grid(*this);
	for (long i = 0; i < rows; i++)
	{
		for (long j = 0; j < cols; j++)
		{
			int a = this->gridElements[i][j] * (-1);
			tmp1Grid.gridElements[i][j] = a;
		}
	}
	return tmp1Grid;
}

bool MyGrid::operator==(MyGrid const &rhs) const                  // equal
{
	if (this->myX != rhs.myX || this->myY != rhs.myY || this->rows != rhs.rows || this->cols != rhs.cols) 
	{ return false; }

	for (long i = 0; i < rows; i++)                
	{
		for (long j = 0; j < cols; j++)
		{
			if (this->gridElements[i][j] != rhs.gridElements[i][j]) { return false; }
		}
	}
	return true;
}          //≈–∂œ «∑Òœ‡µ»

MyGrid operator+(long const& lhs, MyGrid const& rhs)            
{
	MyGrid newGrid(rhs);
	return (newGrid + lhs);
}     

fstream& operator<<(fstream& os, const MyGrid& gridIn)            //output
{
	os << gridIn.myX << " " << gridIn.myY << endl;
	os << gridIn.rows << " " << gridIn.cols << endl;
	for (long i = 0; i < gridIn.rows; i++)
	{
		for (long j = 0; j < gridIn.cols; j++)
		{
			os << gridIn.gridElements[i][j] << " ";
		}
		os << endl;
	}
	os << endl;
	return os;
}
