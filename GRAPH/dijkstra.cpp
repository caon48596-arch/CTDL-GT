#include <bits/stdc++.h>
using namespace std;
const int n = 4;
const int INF = 10000;
#define MAX 10
int S[n + 1];
int D[n + 1];
int C[n + 1][n + 1];

void dijkstra()
{
    S[1] = true;
    for (int i = 2; i <= n; i++)
    {
        D[i] = C[1][i];
    }
    for (int j = 2; j <= n; j++)
    {
        int min = INF;
        int w = -1;
        for (int k = 2; k <= n; k++)
        {
            if (S[k] == false && D[k] < min)
            {
                min = D[k];
                w = k;
            }
        }
        if (w == -1)
        {
            return;
        }
        S[w] = true;
        for (int m = 2; m <= n; m++)
        {
            if (S[m] == false && D[w] + C[w][m] < D[m])
            {
                D[m] = D[w] + C[w][m];
            }
        }
    }
}
int main()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][j] = INF;

    C[1][2] = 7;
    C[2][1] = 7;
    C[1][3] = 9;
    C[3][1] = 9;
    C[2][3] = 10;
    C[3][2] = 10;
    C[2][4] = 15;
    C[4][2] = 15;
    C[3][4] = 11;
    C[4][3] = 11;
    // C[1][6] = 14;
    // C[6][1] = 14;
    // C[3][6] = 2;
    // C[6][3] = 2;
    // C[4][5] = 6;
    // C[5][4] = 6;
    // C[5][6] = 9;
    // C[6][5] = 9;

    // init S
    for (int i = 1; i <= n; i++)
        S[i] = false;

    dijkstra();

    cout << "D[i]:\n";
    for (int i = 1; i <= n; i++)
        cout << "D[" << i << "] = " << D[i] << endl;
}