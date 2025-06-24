#include <iostream>
using namespace std;

int main()
{
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows and columns for Matrix A:";
    cin >> rowsA >> colsA;

    cout << "Enter rows and columns for Matrix B:";
    cin >> rowsB >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication not possible. Columns of A must equal rows of B." << endl;
        return 1;
    }

    int A[100][100], B[100][100], C[100][100] = {0};

    cout << "Enter elements of A (" << rowsA << "x" << colsA << "):" << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of B (" << rowsB << "x" << colsB << "):" << endl;
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result matrix c:" << endl;

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}