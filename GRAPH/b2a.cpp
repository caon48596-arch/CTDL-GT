#include <bits/stdc++.h>
using namespace std;
#define MAX 150
const int INF = 1000;
const int Null = -1;
int A[130][130];
int mark[130];
int front = 0;
int rear = -1;
int Q[MAX];
int FIRST(int x)
{
    for (int i = 97; i < 103; i++)
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
    for (int j = i + 1; j < 103; j++)
    {
        if (A[x][j] == 1)
        {
            return j;
        }
    }
    return Null;
}
void ENQUEUE(int x)
{
    rear++;
    Q[rear] = x;
}
int DEQUEUE()
{
    return Q[front++];
}
int Empty()
{
    return front > rear;
}
void bfs(char canduyet)
{
    int w, y; 
    mark[canduyet] = true;
    ENQUEUE(canduyet);
    while (!Empty())
    {
        y = DEQUEUE();
        w = FIRST(y);
        while (w != Null)
        {
            if (mark[w] == false)
            {
                mark[w] = true;
                cout << "dinh " << char(canduyet) << " ke voi " << (char)w << endl;
                ENQUEUE(w);
            }
            w = NEXT(y, w);
        }
    }
}
void duyet()
{
    for (int i = 97; i < 103; i++)
    {
        mark[i] = false;
    }
    char canduyet;
    cin >> canduyet;

    if (mark[canduyet] == false)
    {
        bfs(canduyet);
    }
}
int main()
{
    A['a']['b'] = 1;
    A['a']['f'] = 1;
    A['a']['d'] = 1;
    A['b']['f'] = 1;
    A['f']['d'] = 1;
    A['d']['b'] = 1;
    A['b']['c'] = 1;
    A['c']['d'] = 1;
    A['e']['f'] = 1;
    A['e']['d'] = 1;

    duyet();
}