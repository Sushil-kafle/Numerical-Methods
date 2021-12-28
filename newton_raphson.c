#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Error 0.000005

float func(float x)
{

    return x * sin(x) + cos(x);
}
float deriv(float x)
{
    return x * cos(x);
}

float calc_C(float a)
{
    float result;
    if (fabs(deriv(a)) < 0.000005)
    {
        printf("tangent is parallel to x-axis.\n");
        exit(0);
    }

    return (a - (func(a) / deriv(a)));
}

int main()
{

    float number, a, c;
    int iteration = 0;
    printf("Enter the value of a\n");
    scanf("%f", &a);

    do
    {
        c = calc_C(a);

        a = c;
        iteration++;

        if (iteration >= 500)
        {
            printf("Cannot find the roots between given a and b");
            exit(1);
        }

    } while (fabs(func(c)) > Error);

    printf("The required root is %f.\n", c);
    printf("The required iteration is %d", iteration);
}