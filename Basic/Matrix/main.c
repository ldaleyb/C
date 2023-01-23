/*Takes user input .txt file and returns number of rows and cols, 
range of first and last rows, average of first and last colums, 
and first and last numbers in the first and last rows. 
To compile: gcc main.c matrix.c
To run: ./a data.txt */

#include <stdio.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("Usage: %s datafile\n", argv[0]);
        return 1;
    }

    FILE *fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        return 2;
    }

    int **matrix;
    int numRows, numCols;
    fscanf(fp, "%d%d", &numRows, &numCols);
    printf("numRows=%d, numCols=%d\n", numRows, numCols);

    matrix = allocateMatrix(numRows, numCols);

    readMatrix(fp, matrix, numRows, numCols);
    printMatrix(matrix, numRows, numCols);


    printf("The range of the first row is %d\n", rangeRow(matrix, numRows, numCols, 0) );
    printf("The range of the last row is %d\n", rangeRow(matrix, numRows, numCols, numRows-1) );
    printf("The average of the first column is %g\n", avgCol(matrix, numRows, numCols, 0) );
    printf("The average of the last column is %g\n", avgCol(matrix, numRows, numCols, numCols-1) );

    printCorners(matrix, numRows, numCols);

    freeMatrix(matrix, numRows, numCols);

    return 0;
}
