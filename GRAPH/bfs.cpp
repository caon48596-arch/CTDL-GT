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
void dfs(int w)
{
    int x, y;
    MakeNull();
    mark[w] = true;
    cout << "dinh la " << w << endl;
    ENQUECE(w);
    while (!Empty())
    {
        x = DEQUECE();
        y = FIRST(x);
        while (y != Null)
        {
            if (mark[y] == false)
            {
                mark[y] = true;
                cout << "dinh la " << y << endl;
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
            dfs(i);
        }
    }
}
int main()
{
    a[0][1];
    a[1][0];
    a[0][2];
    a[2][0];
    a[0][3];
    a[3][0];
    duyet();
}