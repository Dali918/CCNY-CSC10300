#include "HM3_Banda_24241306_Header.h"

//takes a matrix as input and print it in a form of a matrix using tabs.
void print(double array[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout<<endl;
    }
}

//check if two input matrices are equal
bool areEqual(double arrayOne[][N], double arrayTwo[][N])
{
    //compare elements at each index
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //return false if at least one of their values differ
            if (arrayOne[i][j] != arrayTwo[i][j])
                return false;
        }
    }
    return true;
}

//check if an input matrix is an identity matrix
bool isIdentity(double array[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //check if diagonal entries are 1 and nondiagonal entries are 0.
            //matrix is not identical if not
            if (i == j && array[i][j] != 1)
            {
                return false;
            }
            else if (i != j && array[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

//compute the counts of even and odd numbers in matrices
void evenAndOdd(double array[][N], int &numEven, int &numOdd)
{
    numEven = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (isEven(array[i][j]))
            {
                numEven++;
            }
        }
    }

    numOdd = (N * N) - numEven;
}

//return a vector containing the sums of each column in a matrix
vector<double> sumOfColumns(double array[][N])
{
    vector<double> sumCols(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sumCols.at(j) += array[i][j];
        }
    }
    return sumCols;
}

//return a pointer to an array containing the sums of each row
double *sumOfRows(double array[][N])
{
    //zero out the sum of rows aray first
    static double sum[N];   //return array of size N
    for(int i=0; i<N; i++){
        sum[i] =0;
    }
    
    //at each index add to the row index 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum[i] += array[i][j];
        }
    }

    return sum;
}

//sort a matrix by row then by column in ascending order
void sortByRowAndColumn(double array[][N])
{
    //sort by row
    for (int row = 0; row < N; row++)
    {
        //sorting an individual row
        for (int j = 0; j < N; j++)
        {
            //set the current minimum  index, initially element 0 of a row
            int currMinIndex = j, tempMin = currMinIndex;
            //loop through the row and find the next minimum element
            for (int k = currMinIndex + 1; k < N; k++)
            {
                //if an element is less than the current minimum element, save its index and
                //keep looking for another minimum element while in range
                if (array[row][tempMin] > array[row][k])
                {
                    tempMin = k;
                }
            }

            //swap the current minimum element with the 'new' minimum element
            //increment the index of the current minimum element in the next iteration. Elements to the left of this
            //index are sorted
            if (currMinIndex != tempMin)
            {
                double temp = array[row][tempMin];
                array[row][tempMin] = array[row][currMinIndex];
                array[row][currMinIndex] = temp;
            }
        }
    }

    //sort by column
    for (int col = 0; col < N; col++)
    {
        //sorting an individual column
        for (int j = 0; j < N; j++)
        {
            //set the current minimum index and loop through to find teh next current minimum
            int currMinIndex = j, tempMin = currMinIndex;
            for (int k = currMinIndex + 1; k < N; k++)
            {
                if (array[tempMin][col] > array[k][col])
                {
                    tempMin = k;
                }
            }
            if (currMinIndex != tempMin)
            {
                //swap the found minimum with the the current minimum
                double temp = array[tempMin][col];
                array[tempMin][col] = array[currMinIndex][col];
                array[currMinIndex][col] = temp;
            }
        }
    }
}
