#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int **allocateMatrix(int numRows, int numCols)
{
    int **matrix = (int**)malloc(sizeof(int*) * numRows);
    for (int row = 0; row < numRows; row++) {
        matrix[row] = (int*)malloc(sizeof(int) * numCols);
    }
   return matrix;
}

void freeMatrix(int **matrix, int numRows, int numCols)
{
    for (int row = 0; row < numRows; row++) {
        free(matrix[row]);
    }
    free(matrix);
    return;
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols)
{
   for (int row = 0; row < numRows; row++) {
       for (int col = 0; col < numCols; col++) {
           fscanf(fp, "%d", &matrix[row][col]);
       }
   }
    return;
}

void printMatrix(int **matrix, int numRows, int numCols)
{
   for (int row = 0; row < numRows; row++) {
       for (int col = 0; col < numCols; col++) {
           printf("%d ", matrix[row][col]);
       }
       printf("\n");
   }
   return;
}

int rangeRow(int **matrix, int numRows, int numCols, int r)
{
    int max = matrix[r][0];
    int min = matrix[r][0];
    for (int col = 0; col < numCols; col++) {
        if (matrix[r][col] >= max) {
            max = matrix[r][col];
        }
        if (matrix[r][col] <= min) {
            min = matrix[r][col];
        }
    }
    int range = max - min;
   return range;
}

double avgCol(int **matrix, int numRows, int numCols, int c)
{
    int sum = 0;
    for (int row = 0; row < numRows; row++) {
        sum+= matrix[row][c];
    }
    double avg = (double)sum / numRows;
   return (double)avg;
}

void printCorners(int **matrix, int numRows, int numCols)
{
   printf("%d %d\n", matrix[0][0], matrix[0][numCols-1]);
   printf("%d %d\n", matrix[numRows-1][0], matrix[numRows-1][numCols-1]);

   return;
}