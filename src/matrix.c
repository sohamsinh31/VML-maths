#include "matrix.h"

Matrix createMatrix(int rows, int cols)
{
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int *)malloc(rows * cols * sizeof(int));
    return mat;
}

int get(Matrix mat, int row, int col)
{
    return mat.data[row * mat.cols + col];
}

void set(Matrix mat, int row, int col, int value)
{
    mat.data[row * mat.cols + col] = value;
}

void destroyMatrix(Matrix mat)
{
    free(mat.data);
}