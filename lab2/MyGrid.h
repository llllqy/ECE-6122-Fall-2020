/*
Author: <Qingyuan Liu>
Class: ECE4122 or ECE6122
Last Date Modified: <2/10/2020>
Description:
    Constructe a class called MyGrid that has a member variable gridElements 
that is a dynamic two-dimensional array of elements (type long) of m rows by n columns.
*/

#pragma once
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class MyGrid
{
public:
    MyGrid() {  };
    bool loadGridFromFile(const string& filename);
    void zeroOutGrid();
    long getNumRows() const;
    long getNumCols() const;

    MyGrid operator+(MyGrid const&) const;
    MyGrid operator-(MyGrid const&) const;

    MyGrid operator+(long const&) const;

    friend MyGrid operator+(long const& lhs, MyGrid const& rhs);
  
    // Addition assignment 
    MyGrid& operator+=(MyGrid const&);
    // Increment
    MyGrid& operator++(); // Prefix
    MyGrid operator++(int); // Postfix

    MyGrid& operator--(); // Prefix
    MyGrid operator--(int); // Postfix

    MyGrid operator-() const;

    bool operator==(MyGrid const&) const;

    friend fstream& operator<<(fstream& os, const MyGrid& gridIn);

private:
    long myX, myY;
    long rows, cols;                       //the rows and columns of the two-dimensional array
    vector<vector<long>> gridElements;
};