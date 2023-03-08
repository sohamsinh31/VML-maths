#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct vector
{
    float x;
    float y;
    float z;
} Vector;

Vector *vector(int x, int y, int z);
void print_vector(Vector *v);
Vector *add_vector(Vector *v1, Vector *v2);
Vector *sub_vector(Vector *v1, Vector *v2);