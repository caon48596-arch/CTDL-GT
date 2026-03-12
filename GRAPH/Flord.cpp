#include <bits/stdc++.h>
using namespace std;
const int n = 5;
const int INF = 1000;
int A[n][n];
int D[n][n];
int P[n][n];
void FLORDY()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            D[i][j] = A[i][j];
            P[i][j] = 0;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][k] != INF && A[k][j] != INF)
                {
                    if (A[i][k] + A[k][j] < A[i][j])
                    {
                        A[i][j] = A[i][k] + A[k][j];
                        P[i][j] = k;
                    }
                }
            }
        }
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                A[i][j] = 0;
            }
            else
            {
                A[i][j] = INF;
            }
        }
    }
    A[0][1] = 4;
    A[1][0] = 4;
    A[0][4] = 10;
    A[4][0] = 10;
    A[3][1] = 2;
    A[1][3] = 2;
    A[2][1] = 5;
    A[1][2] = 5;
    FLORDY();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "P[" << i << "][" << j << "] = " << P[i][j] << endl;
            ;
        }
    }
}