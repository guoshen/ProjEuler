//Problem:Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//How many such routes are there through a 20×20 grid?
// Dynamic Programming Approach
//Solved By: Shengyuan Guo in 2013

#include <iostream>

using namespace std;

unsigned long  latticePaths(int size)
{
    int arrSize=size+1;
    //array to memoize the process
    unsigned long numPaths[arrSize][arrSize];
    for(int i=0; i<arrSize;i++)
    {
        for(int j=0; j<arrSize;j++)
        {
            numPaths[i][j]=1;
        }
    }

    for(int j=1; j<=size;j++)
    {
        int i,k;

        //for each column go up diagonally filling up the cells (/)
       //ignore the cells on the upper and left edges(they only have one path leading to them)
        for(int i=1, k=j;k>0 && i<=size;k--,i++)
            numPaths[i][k]=numPaths[i-1][k]+numPaths[i][k-1];

    }

    for(int i=2;i<=size;i++)
    {
        //for each row go up diagonally filling up the cells
        //ignore row 1 as we already filled the diagonal previously

        for(int j=size,k=i;k<=size && j>0;k++, j--)
         numPaths[i][k]=numPaths[i-1][k]+numPaths[i][k-1];
    }
    return numPaths[20][20];
}

int main()
{
	cout<<"The number of paths for a grid of size 20 is: "<<latticePaths(20);
}


