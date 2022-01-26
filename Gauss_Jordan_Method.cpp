#include <iostream>
using namespace std;

void getInput(float **matrix, int size)
{

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j <= size; j++)
        {
            cout << "Enter a[" << i << j << "] element \n";
            cin >> matrix[i][j];
        }
    }
}
void Display(float **matrix, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "[ ";
        for (int j = 0; j <= size; j++)
        {
            if (j == size)
            {
                cout << " : ";
            }
            cout << matrix[i][j] << "\t";
        }
        cout << "]\n";
    }
}

void calculate(float **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i][i] == 0)
        {
            cout << "Error";
            exit(1);
        }
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {

                float temp = matrix[j][i] / matrix[i][i];
                cout << "R" << j + 1 << " -> " << matrix[j][i] << "/" << matrix[i][i] << "R" << i + 1 << " - R" << j + 1 << "\n\n";
                for (int k = 0; k <= size; k++)
                {

                    matrix[j][k] = (temp * matrix[i][k]) - matrix[j][k];
                }
                Display(matrix, size);
                cout << "\n\n\n";
            }
        }
    }

    cout << "The required values are : ";
    for (int i = 0; i < size; i++)
    {
        cout << matrix[i][size] / matrix[i][i] << "\t";
    }
}

int main()
{

    int row, column;
    cout << "Enter the size of the matrix: \n";
    cin >> row;
    column = row + 1;

    float **matrix = new float *[column];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[column];
    }

    getInput(matrix, row);

    cout << "\nRe - writting it in matrix form: \n\n";

    Display(matrix, row);
    calculate(matrix, row);

    for (int i = 0; i < column; i++)
    {

        delete[] matrix[i];
        delete[] matrix;
    }
}

// 4 1 2 3 -1 10 2 3 -3 -1 1 2 -1 2 3 7 3 2 -4 3 2
// 1 0 0 2 0 1 0 0 0 0 1 -1
// 3 1 2 3 4 2 3 3 4 2 4 5 3
// 3 1 1 1 9 2 -3 4 13 3 4 5 40