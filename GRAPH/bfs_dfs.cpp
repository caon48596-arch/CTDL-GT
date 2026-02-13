#include <bits/stdc++.h>
using namespace std;
#define MAX 6
const int n = 6;
const int Null = -1;
int Q[MAX];
int rear;
int front;
int a[n][n];
int mark[n];
void MakeNull()
{
    int rear = -1;
    int front = 0;
}
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
void dfs(int x)
{
    mark[x] = true;
    cout << " da danh dau dinh " << x << endl;
    int w = FIRST(x);
    while (w != Null)
    {
        if (mark[w] == false)
        {
            dfs(w);
        }
        w = NEXT(x, w);
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
int Empty()
{
    return front > rear;
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
void bfs(int v)
{
    int x, y;
    MakeNull();
    mark[v] = true;
    cout << "dinh " << v << endl;
    ENQUECE(v);
    while (!Empty())
    {
        y = DEQUECE();
        x = FIRST(y);
        while (x != Null)
        {
            if (mark[x] == false)
            {
                mark[x] = true;
                cout << "dinh " << x << endl;
                ENQUECE(x);
            }
            x = NEXT(y, x);
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
    a[0][4] = 1;
    a[4][0] = 1;
    a[0][3] = 1;
    a[3][0] = 1;
    a[1][2] = 1;
    a[2][1] = 1;
    a[2][5] = 1;
    a[5][2] = 1;
    int w;
    // for (int i = 0; i < n; i++)
    // {
    //     w = FIRST(i);
    //     cout << " dinh  " << i << " ke voi " << w << endl;
    //     while (w != Null)
    //     {
    //         cout << " dinh  " << i << " ke voi " << w << endl;
    //         w = NEXT(i, w);
    //     }
    // }
    // duyetdfs();
    duyetbfs();
}