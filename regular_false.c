#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define error 0.0005

float func(float x)
{
    return pow(x, 4) - 32;
}
float calc_c(float a, float b)
{
    return ((a * func(b) - b * func(a))) / ((func(b) - func(a)));
}

float regular_fal(float a, float b, float c)
{
    c = calc_c(a, b);
    static int iteration = 1;
    if (iteration == 100)
    {
        printf("Roots doesnot exist\n");
        exit(0);
    }
    if (fabs(func(c)) < error)
    {
        return c;
        iteration++;
    }
    else if (func(c) < 0)
    {
        iteration++;
        regular_fal(c, b, c);
    }
    else
    {
        iteration++;
        regular_fal(a, b, c);
    }
}

int main()
{
    int iteration = 0;
    float a = 0, b = 1;
    float c;
    float root;
    while ((func(a) * func(b)) > 0)
    {
        if (iteration == 100)
        {
            printf("values of a and b cannot be found\n");
            exit(0);
        }
        a++;
        b++;
    }
    if (func(a) > 0)
    {
        c = a;
        a = b;
        b = c;
    }
    c = calc_c(a, b);

    printf("%f", root);
}