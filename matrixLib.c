// matrixLib.c

#include "matrixLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *returnVector(int size)
{
    float *array = (float *)malloc(size * sizeof(float));
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    return array;
}

float **returnMatrix(int row, int col)
{
    float **array = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        array[i] = (float *)malloc(col * sizeof(float));
    }
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            array[i][k] = 0;
        }
    }
    return array;
}

void freeMatrix(float **mat, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

float mean(float *vec, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += vec[i];
    }
    float mean = sum / size;
    printf("Mean: %f", mean);
    return mean;
}

float covariance(float *vec1, float *vec2, int size)
{
    float covarianceValue = 0;
    float meanvec1 = mean(vec1, size);
    float meanvec2 = mean(vec2, size);
    float *multpvec = returnVector(size);
    for (int i = 0; i < size; i++)
    {
        vec1[i] -= meanvec1;
        vec2[i] -= meanvec2;
    }
    for (int i = 0; i < size; i++)
    {
        multpvec[i] = vec1[i] * vec2[i];
        covarianceValue += multpvec[i];
    }
    covarianceValue /= (size - 1);
    printf("Covariance Value : %f", covarianceValue);
    return covarianceValue;
}

float correlation(float *vec1, float *vec2, int size)
{
    float covarianceValue = covariance(vec1, vec2, size);
    float standardDeviation1 = sqrt(covariance(vec1, vec1, size));
    float standardDeviation2 = sqrt(covariance(vec2, vec2, size));
    float correlationValue = covarianceValue / (standardDeviation1 * standardDeviation2);
    printf("Correlation: %f", correlationValue);
    return correlationValue;
}

float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2)
{
    float **multpMatrix = returnMatrix(row1, col2);
    if (row2 == col1)
    {
        for (int m = 0; m < row1; m++)
        {
            for (int n = 0; n < col2; n++)
            {
                float sum = 0;
                for (int k = 0; k < row1; k++)
                {
                    sum += mat1[m][k] * mat2[k][n];
                }
                multpMatrix[m][n] = sum;
            }
        }
        return multpMatrix;
    }
    else
    {
        printf("row1 and col2 must be equal to do matrix multiplication");
        return NULL;
    }
}

float **matrixTranspose(float **mat, int row, int col)
{
    float **transpose = returnMatrix(col, row);
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            transpose[k][i] = mat[i][k];
        }
    }
    return transpose;
}

float *rowMeans(float **mat, int row, int col)
{
    float *rMean = returnVector(row);
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            rMean[i] += mat[i][k];
        }
        rMean[i] /= row;
    }
    return rMean;
}

float *columnMeans(float **mat, int row, int col)
{
    float *cMean = returnVector(col);
    for (int i = 0; i < col; i++)
    {
        for (int k = 0; k < row; k++)
        {
            cMean[i] += mat[k][i];
        }
        cMean[i] /= col;
    }
    return cMean;
}

float **covarianceMatrix(float **mat, int row, int col)
{
    float *columnMeansVector = columnMeans(mat, row, col);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            mat[j][i] -= columnMeansVector[i];
        }
    }
    float **matrixTransposeValue = matrixTranspose(mat, row, col);
    float **matrixMultiplicationValue = matrixMultiplication(mat, matrixTransposeValue, row, col, row, col);

    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            matrixMultiplicationValue[i][k] /= row;
        }
    }

    return matrixMultiplicationValue;
}

float determinant(float **mat, int row)
{
    float determinantofMatrix = 0;
    float **matrix = (float **)calloc(row, sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (float *)realloc(matrix[i], (row + 2) * sizeof(float));
        for (int k = 0; k < row + 2; k++)
        {
            // Your determinant calculation logic here
        }
    }
    freeMatrix(matrix, row);

    return determinantofMatrix;
}

void printVector(float *vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%f ", vec[i]);
    }
}

void printMatrix(float **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}

void ikiBoyutluDiziDoldur(float **mat, int row, int col, int seed)
{
    srand(seed);
    int i, j;
    for (int i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            mat[i][j] = rand() % 10 + 1;
        }
    }
}

void tekBoyutluDiziyiDoldur(float *vec, int size, int seed)
{
    srand(seed);
    for (int i = 0; i < size; i++)
    {
        vec[i] = rand() % 10 + 1;
    }
}
