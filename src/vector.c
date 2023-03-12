#include "vectors.h"

Vector *vector(int x, int y, int z)
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

void print_vector(Vector *v)
{
    printf("\nx: %f y: %f z: %f", v->x, v->y, v->z);
}

Vector *add_vector(Vector *v1, Vector *v2)
{
    Vector *sum = (Vector *)malloc(sizeof(Vector));
    sum->x = v1->x + v2->x;
    sum->y = v1->y + v2->y;
    sum->z = v1->z + v2->z;
    return sum;
}

Vector *sub_vector(Vector *v1, Vector *v2)
{
    Vector *sum = (Vector *)malloc(sizeof(Vector));
    sum->x = v1->x - v2->x;
    sum->y = v1->y - v2->y;
    sum->z = v1->z - v2->z;
    return sum;
}