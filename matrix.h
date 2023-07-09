#include <iostream>
using namespace std;

class matrix
{
public:
    int rows, columns;
    int **m;

    matrix(matrix &a)
    {
        rows = a.rows;
        columns = a.columns;
        m = a.m;
    }

    void allocSpace()
    {
        m = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            m[i] = new int[columns];
        }
    }
    matrix(){};
    matrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        allocSpace();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "enter value of matrix[" << i << "][" << j << "] :";
                cin >> m[i][j];
            }
        }
    }

    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    void T()
    {
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << m[j][i] << " ";
            }
            cout << endl;
        }
    }

    void operator+(matrix &a)
    {
        if (a.rows != rows || a.columns != columns)
        {
            throw "size is not same ";
        }
        cout << "addition of both matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << m[i][j] + a.m[i][j] << " ";
            }
            cout << endl;
        }
    }

    void operator*(matrix &a)
    {
        if (rows != a.columns || columns != a.rows)
        {
            throw "not compatible for matrix product";
        }
        cout << "product of both matrix: " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < a.columns; j++)
            {
                int sum = 0;
                for (int k = 0; k < columns; k++)
                {
                    sum += m[i][k] * a.m[k][j];
                }
                cout << sum << " ";
            }
            cout << endl;
        }
    }

    ~matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
    }
};
