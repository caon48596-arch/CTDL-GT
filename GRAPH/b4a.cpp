#include <bits/stdc++.h>
using namespace std;
const int INF = 1000;
const int Null = -1;
const int n = 130;
int D[130];
int C[130];
int A[n][n];
int main()
{
    for (int i = 'A'; i <= 'H'; i++)
    {
        for (int j = 'A'; j <= 'H'; j++)
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
    A['A']['B'] = 2;
    A['B']['A'] = 2;
    A['A']['C'] = 3;
    A['C']['A'] = 3;
    A['B']['D'] = 2;
    A['D']['B'] = 2;
    A['C']['D'] = 1;
    A['D']['C'] = 1;
    A['D']['E'] = 2;
    A['E']['D'] = 2;
    A['D']['F'] = 4;
    A['F']['D'] = 4;
    A['E']['F'] = 1;
    A['F']['E'] = 1;
    A['E']['G'] = 2;
    A['G']['E'] = 2;
    A['F']['G'] = 2;
    A['G']['F'] = 2;
    A['F']['H'] = 1;
    A['H']['F'] = 1;
    A['G']['H'] = 3;
    A['H']['G'] = 3;