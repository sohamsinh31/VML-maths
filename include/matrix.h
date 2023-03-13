#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct
{
    int rows;
    int cols;
    int *data;
} Matrix;

Matrix createMatrix(int rows, int cols);

int get(Matrix mat, int row, int col);

void set(Matrix mat, int row, int col, int value);

void destroyMatrix(Matrix mat);

// void print_matrix(int matrix[][][]);