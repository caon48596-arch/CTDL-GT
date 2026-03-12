#include <bits/stdc++.h>
using namespace std;
#define MAX 5
const int n = 5;
const int Null = -1;
int a[n][n];
int Q[MAX];
int mark[n];
int FIRST(int v)
{
    for (int i = 0; i < n; i++)
    {
        if (a[v][i] == 1)
        {
            return i;
        }
    }
    return Null;
}
int NEXT(int x, int i)
{
    for (int j = i + 1; j < n; j++)
    {

        if (a[x][j] == 1)
        {
            return j;
        }
    }
    return Null;
}
void bfs(int x)
{
    mark[x] = true;
    cout << "da tham dinh " << x << endl;
    int z = FIRST(x);
    while (z != Null)
    {
        if (mark[z] == false)
        {
            bfs(z);
        }
        z = NEXT(x, z);
    }
}
void duyet()
{
    for (int i = 0; i < n; i++)
    {
        mark[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == false)
        {
            bfs(i);
        }
    }
}
int main()
{
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][2] = 1;
    a[2][1] = 1;
    a[3][2] = 1;
    a[2][3] = 1;
    a[3][4] = 1;
    a[4][3] = 1;
    int x;
    for (int i = 0; i < n; i++)
    {
        x = FIRST(i);

        while (x != Null)
        {
            cout << "diem " << i << " ke voi diem " << x << endl;
            x = NEXT(i, x);
        }
    }
    duyet();
}