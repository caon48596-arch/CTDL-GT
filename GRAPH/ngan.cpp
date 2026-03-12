#include <bits/stdc++.h>
using namespace std;

const int n = 4;
const int INF = 1000;

int A[n][n];
int C[n][n];
int P[n][n];

void Floyd()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = C[i][j];
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
                        A[i][j] = A[i][k] + A[k][j]; // Cập nhật đường ngắn hơn
                        P[i][j] = k;                 // Ghi nhớ trạm trung chuyển k
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
            C[i][j] = INF;
        }
    }

    C[0][1] = 2;
    C[1][0] = 2;
    C[1][2] = 5;
    C[2][1] = 5;
    C[0][3] = 10;
    C[3][0] = 10;

    // for (int i = 0; i < n; i++)
    // {
    //     C[i][i] = 0;
    // }

    Floyd();

    cout << "Ma tran A sau Floyd:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == INF)
                cout << "INF ";
            else
                cout << A[i][j] << " ";
        }
        cout << endl;
    }
}