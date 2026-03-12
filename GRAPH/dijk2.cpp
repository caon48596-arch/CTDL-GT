#include <bits/stdc++.h>
using namespace std;

const int n = 5; // ví dụ hình có 5 đỉnh
const int INF = 10000;

int S[n + 1];        // tập S
int D[n + 1];        // khoảng cách
int P[n + 1];        // đỉnh trước
int C[n + 1][n + 1]; // ma trận trọng số

void dijkstra()
{
    S[1] = 1; // S = {1}
    D[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        P[i] = 1;
        D[i] = C[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        int minVal = INF;
        int w = -1;
        for (int k = 2; k <= n; k++)
        {
            if (!S[k] && D[k] < minVal)
            {
                minVal = D[k];
                w = k;
            }
        }

        if (w == -1)
            return;
        S[w] = 1;
        for (int u = 2; u <= n; u++)
        {
            if (S[u] == false && D[w] + C[w][u] < D[u])
            {
                D[u] = D[w] + C[w][u];
                P[u] = w;
            }
        }
    }
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                C[i][j] = 0;
            else
                C[i][j] = INF;
        }
    }
    C[1][2] = 10;
    C[2][1] = 10;
    C[1][5] = 100;
    C[5][1] = 100;
    C[1][3] = 30;
    C[3][1] = 30;
    C[3][5] = 60;
    C[5][3] = 60;
    C[2][4] = 50;
    C[4][2] = 50;
    C[4][5] = 10;
    C[5][4] = 10;

    // init S
    for (int i = 1; i <= n; i++)
        S[i] = 0;

    dijkstra();

    cout << "Khoang cach ngan nhat tu dinh 1:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "D[" << i << "] = " << D[i] << endl;
    }

    cout << "\nP[i] (dinh truoc):\n";
    for (int i = 2; i <= n; i++)
    {
        cout << "P[" << i << "] = " << P[i] << endl;
    }
}