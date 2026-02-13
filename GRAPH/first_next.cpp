#include <bits/stdc++.h>
using namespace std;
const int Null = -1;
const int n = 4;
int mark[n];
int a[n][n];
#define max 4
int rear;
int front;
int Q[max];
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
int Empty()
{
    return front > rear;
}
void MakeNull()
{
    front = 0;
    rear = -1;
}
void ENQUECE(int x)
{
    rear++;
    Q[rear] = x;
}
int DEQUECE()
{
    return Q[front++];
}
int NEXT(int v, int i)
{
    for (int j = i + 1; j < n; j++)
    {
        if (a[v][j] == 1)
        {
            return j;
        }
    }
    return Null;
}
void bfs(int v)
{
    int x, y;
    MakeNull();
    mark[v] = true;
    cout << "cac dinh la " << v << endl;
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
                cout << "cac dinh la " << y << endl;
                ENQUECE(y);
            }
            y = NEXT(x, y);
        }
    }
}
void dfs(int i)
{
    cout << "cac dinh la " << i << endl;
    mark[i] = true;
    int w = FIRST(i);
    while (w != Null)
    {
        if (mark[w] == false)
        {
            dfs(w);
        }
        w = NEXT(i, w);
    }
}
void duyetdfs()
{
    for (int i = 0; i < n; i++)
    {
        mark[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == false)
        {
            dfs(i);
        }
    }
}
void duyetbfs()
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
    a[0][2] = 1;
    a[2][0] = 1;
    a[3][0] = 1;
    a[0][3] = 1;
    // for (int k = 0; k < n; k++)
    // {
    //     int i = FIRST(k);
    //     while (i != Null)
    //     {
    //         cout << "ke voi " << k << " la " << i << endl;
    //         i = NEXT(k, i);
    //     }
    // }
    // duyetdfs();
    duyetbfs();
}