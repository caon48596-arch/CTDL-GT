#include <bits/stdc++.h>
using namespace std;

const int n = 4;
const int INF = 1000;

int S[n];
int C[n][n];
int D[n];

void dijkstra()
{
    S[0] = true;
    for (int i = 1; i < n; i++)
    {
        D[i] = C[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        int min = INF;
        int w = -1;
        for (int j = 1; j < n; j++)
        {
            if (min > D[j] && S[j] == false)
            {
                min = D[j];
                w = j;
            }
        }
        if (w == -1)
        {
            return;
        }
        S[w] = true;
        for (int k = 1; k < n; k++)
        {
            if (S[k] == false && D[w] + C[w][k] < D[k])
            {
                D[k] = D[w] + C[w][k];
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
    C[2][1] = 5;
    C[1][2] = 5;
    C[0][3] = 10;
    C[3][0] = 10;
    for (int i = 1; i < n; i++)
    {
        S[i] = false;
    }
    dijkstra();
    for (int i = 1; i < n; i++)
    {
        cout << "D[" << i << "] = " << D[i] << endl;
    }
}