#include <bits/stdc++.h>
using namespace std;
const int INF = 1000;
int A[130][130];

int main()
{
    for (int i = 97; i < 97 + 6; i++)
    {
        for (int j = 97; j < 97 + 6; j++)
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

    A['a']['b'] = 3;
    A['a']['f'] = 5;
    A['a']['d'] = 4;
    A['b']['f'] = 1;
    A['f']['d'] = 2;
    A['b']['d'] = 3;
    A['b']['c'] = 1;
    A['c']['d'] = 2;
    A['e']['f'] = 2;
    A['e']['d'] = 3;
    for (int i = 97; i < 97 + 6; i++)
    {
        for (int j = 97; j < 97 + 6; j++)
        {
            if (A[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }
}
