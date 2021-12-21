#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define error 0.000005

float func(float x)
{
    return pow(x, 4) - 32;
}

// float func(float x)
// {

//     return (2 * log(x) + 3);
// }

// float func(float x)
// {
//     double result = x;
//     return (exp(result) + 3 * x - 4);
// }

float bisect(float a, float b, float c)
{
    static int iteration = 0;

    if (iteration == 100)
    {
        printf("Root doesnot exist \n");
        exit(0);
    }

    if (fabs(func(c)) < error)
    {
        iteration++;
        return c;
    }
    else if (func(c) > 0)
    {
        iteration++;
        bisect(a, c, (a + c) / 2);
    }
    else
    {
        iteration++;
        bisect(c, b, (a + b) / 2);
    }
}

int main()
{
    int i, iteration = 0, max_iteration = 100;
    float a = 0, b = 1, c, root;
    while (1)
    {
        if (iteration == max_iteration)
        {
            printf("Cannot find value of a and b");
            exit(0);
        }
        if ((func(a) * func(b)) < 0)
        {
            break;
        }
        a++;
        b++;
        iteration++;
    }
    if (func(a) > 0)
    {
        c = a;
        a = b;
        b = c;
    }
    root = bisect(a, b, (a + b) / 2);
    printf("%f is approximation root", root);
}