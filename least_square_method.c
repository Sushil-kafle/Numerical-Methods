#include <stdio.h>
#include <math.h>

void getData(float *a, int size, char c)
{
    printf("Enter %d value of %c: ", size, c);
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &a[i]);
    }
}

void calculate(float *sumX, float *sumY, float *sumXY, float *X_2, float *a, float *b, int size)
{
    for (int i = 0; i < size; i++)
    {
        *sumX += a[i];
        *sumY += b[i];
        *sumXY += a[i] * b[i];
        *X_2 += a[i] * a[i];
    }
}

void calculate(float *sumX, float *sumY, float *sumXY, float *X_2, float *x, float *y, int size)
{

    for (int i = 0; i < size; i++)
    {
        y[i] = log(y[i]);
        *sumX += x[i];
        *sumY += y[i];
        *sumXY += x[i] * y[i];
        *X_2 += x[i] * x[i];
    }
}

int main()
{
    int size;
    float a, b, x[20], y[20];
    float sumX = 0, sumY = 0, sumXY = 0, X_2 = 0;
    printf("Enter the number of pair of data\n");
    scanf("%d", &size);
    getData(x, size, 'x');
    getData(y, size, 'y');

    calculate(&sumX, &sumY, &sumXY, &X_2, x, y, size);

    a = (sumY * X_2 - sumXY * sumX) / (size * X_2 - sumX * sumX);
    b = (size * sumXY - sumY * sumX) / (size * X_2 - sumX * sumX);

    if (b < 0)
    {
        b = b * -1;
        printf(" %f - %f x", a, b);
    }
    else
    {
        printf(" %f + %f x", a, b);
    }

    return 0;
}
