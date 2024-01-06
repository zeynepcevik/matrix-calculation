// main.c

#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h"

#define N 3

int main()
{
    // Example usage of matrixLib functions

    // 1. Creating matrices
    float **matrix1 = returnMatrix(3, 3);
    float **matrix2 = returnMatrix(3, 3);

    // 2. Filling matrices with random values
    ikiBoyutluDiziDoldur(matrix1, 3, 3, 42);  // Using seed 42
    ikiBoyutluDiziDoldur(matrix2, 3, 3, 24);  // Using seed 24

    // 3. Printing matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3, 3);

    // 4. Matrix multiplication
    float **resultMatrix = matrixMultiplication(matrix1, matrix2, 3, 3, 3, 3);
    printf("\nMatrix Multiplication Result:\n");
    printMatrix(resultMatrix, 3, 3);

    // 5. Transposing a matrix
    float **transposedMatrix = matrixTranspose(matrix1, 3, 3);
    printf("\nTransposed Matrix:\n");
    printMatrix(transposedMatrix, 3, 3);

    // 6. Row and column means
    float *rowMeansVec = rowMeans(matrix1, 3, 3);
    float *colMeansVec = columnMeans(matrix1, 3, 3);

    printf("\nRow Means:\n");
    printVector(rowMeansVec, 3);

    printf("\nColumn Means:\n");
    printVector(colMeansVec, 3);

    // 7. Covariance matrix
    float **covarianceMat = covarianceMatrix(matrix1, 3, 3);
    printf("\nCovariance Matrix:\n");
    printMatrix(covarianceMat, 3, 3);

    // 8. Determinant
    float det = determinant(matrix1, 3);
    printf("\nDeterminant of Matrix 1: %f\n", det);

    // 9. Freeing memory
    freeMatrix(matrix1, 3);
    freeMatrix(matrix2, 3);
    freeMatrix(resultMatrix, 3);
    freeMatrix(transposedMatrix, 3);
    free(rowMeansVec);
    free(colMeansVec);
    freeMatrix(covarianceMat, 3);

    return 0;
}
