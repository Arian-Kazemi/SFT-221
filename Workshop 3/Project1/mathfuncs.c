#include "mathfuncs.h"
#include <stdio.h>
double square(double n)
{
    return n * n;
}

double cube(double n)
{
    return n * n * n;
}

int main(void)
{
    printf("Square of 2's is %lf\n" , square(2));
    printf("Cube is 2's is %lf\n" , cube(2));
    return 0;
}