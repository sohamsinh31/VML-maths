#include "vml.h"

void vector_test()
{
    Vector *v1, *v2, *sum;
    v1 = vector(10, 20, 30);
    v2 = vector(40, 50, 60);
    sum = add_vector(v1, v2);

    print_vector(v1);
    print_vector(v2);
    print_vector(sum);
}

int main(int argc, char const *argv[])
{
    return 0;
}
