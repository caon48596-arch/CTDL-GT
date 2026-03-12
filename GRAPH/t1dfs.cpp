#include <bits/stdc++.h>
using namespace std;
#define MAX 5
int front = 0;
int rear = -1;
int Q[MAX];
const int n = 4;
const int Null = -1;
int mark[n];
int a[n][n];
int FIRST(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[x][i] == 1)
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
int ENQUECE(int x)
{
    rear++;
    Q[rear] = x;
}
int DEQUECE()
{
    return Q[front++];
}
int Empty()
{
    return front > rear;
}
void bfs(int v)
{
    int x, y;
    mark[v] = true;
    cout << "dinh " << v << endl;
    ENQUECE(v);
    while (!Empty())
    {
        x = DEQUECE();
        y = FIRST(x);
        while (y != Null)
        {
            if (mark[y] == false)
            {
                mark[y] = true;
                cout << "dinh " << y << endl;

                ENQUECE(y);
            }
            y = NEXT(x, y);
        }
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
    for (int i = 0; i < n; i++)
    {
        int x = FIRST(i);
        while (x != Null)
        {
            cout << "dinh " << x << " giap voi diem " << i << endl;
            x = NEXT(i, x);
        }
    }
    duyet();
}
