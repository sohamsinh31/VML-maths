#include "vml.h"

void print_box(int width, int height)
{
    int i, j, k;
    // int width = 50, height = 20;
    int matrix[3][2] = {{1,2},{2,3},{5,6}};
    int row = sizeof(matrix) / sizeof(matrix[0]);
    for (k = 0; k < width; k++)
    {
        printf("*");
    }
    for (i = 0; i < height; i++)
    {
        printf("\n");
        for (j = 0; j < width; j++)
        {
            if (j == 0)
            {
                printf("*");
            }
            else if (j == width - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
    }
    printf("\n");
    for (k = 0; k < width; k++)
    {
        printf("*");
    }
}