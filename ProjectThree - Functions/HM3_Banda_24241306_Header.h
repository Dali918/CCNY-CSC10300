#ifndef HEADERONE_H
#define HEADERONE_H

#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <cassert>
using namespace std;
int const N = 3;

//MATRIX FUNCTIONS:


//takes a matrix as input and print it in a form of a matrix using tabs.
void print(double array[][N]);
//checks corresponding elements of two given matrices and returns true if they were all equal
bool areEqual(double arrayOne[][N], double arrayTwo[][N]);
//takes a matrix as input and return true if the matrix is an identity matrix.
bool isIdentity(double array[][N]);
//checks if a number is even or odd.
inline bool isEven(double num) { return fmod(num, 2) == 0; }
//takes a matrix as input and even, odd count by reference as input. returning the number of even and odd numbers
void evenAndOdd(double array[][N], int &numEven, int &numOdd);
/*function that takes a matrix as input and returns a vector of sum of columns of matrix. The first element of the vector would be the sum of the first column of the matrix, the second element would be the sum of the second column, and so on.*/
vector<double> sumOfColumns(double array[][N]);
double *sumOfRows(double array[][N]);
//takes a matrix and sort its values first by row and then by column in-place
void sortByRowAndColumn(double array[][N]);




#endif