#include <bits/stdc++.h>
using namespace std;
const int INF = 1000;
int A[130][130];
const int Null = -1;
int FIRST(int x)
{
    for (int i = 97; i < 130; i++)
    {
        if (A[x][i] == 1)
        {
            return i;
        }
    }
    return Null;
}
int NEXT(int x, int i)
{
    for (int j = i + 1; j < 130; j++)
    {
        if (A[x][j] == 1)
        {
            return j;
        }
    }
    return Null;
}
int main()
{

    A['a']['b'] = 1;
    A['a']['f'] = 1;
    A['a']['d'] = 1;
    A['b']['f'] = 1;
    A['f']['d'] = 1;
    A['b']['d'] = 1;
    A['b']['c'] = 1;
    A['c']['d'] = 1;
    A['e']['f'] = 1;
    A['e']['d'] = 1;
    for (int i = 97; i < 130; i++)
    {
        int w = FIRST(i);
        while (w != Null)
        {

            cout << "diem ke cua " << char(i) << " la " << char(w) << endl;
            w = NEXT(i, w);
        }
    }
}