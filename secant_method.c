#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Error 0.000005

float func(float x)
{

    return x * sin(x) + cos(x);
}

float calc_C(float a, float b)
{
    if (fabs(func(b) - func(a)) < 0.0005)
    {
        printf("secant is parallel to x-axis. Cannot find the roots\n");
        exit(0);
    }
    return ((a * func(b) - b * func(a)) / (func(b) - func(a)));
}

int main()
{

    float number, a, b, c;
    int iteration = 0;
    printf("Enter the value of a and b\n");
    scanf("%f%f", &a, &b);

    do
    {
        c = calc_C(a, b);

        a = b;
        b = c;
        iteration++;

        if (iteration >= 500)
        {
            printf("Cannot find the roots between given a and b");
            exit(1);
        }

    } while (fabs(func(c)) > Error);

    printf("The required root is %f.\n", c);
    printf("The required iteration is %d.", iteration);
}