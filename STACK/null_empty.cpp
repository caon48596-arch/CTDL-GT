#include <bits\stdc++.h>
using namespace std;
#define MAXLEGTH 10
typedef int elemenType;
typedef struct
{
    elemenType et[10];
    int Top;
} Stack;
void makenull(Stack *s)
{
    s->Top = MAXLEGTH;
}
void empty(Stack *s)
{
    s->Top == MAXLEGTH;
}
void fullstack(Stack *s)
{
    s->Top == 0;
}
void push(elemenType X, Stack *s)
{
    if (s->Top == 0)
    {
        cout << "sai";
    }
    else
    {
        s->Top = s->Top - 1;
        s->et[s->Top] = X;
    }
}
void pop(Stack *s)
{
    if (s->Top != 0)
    {
        // s->Top = s->Top + 1;
        cout << s->et[s->Top + 1] << ' ';
    }
}
void top(Stack *s, int value)
{
    if (s->Top != 0)
    {
        for (int i = 0; i < value; i++)
        {
            cout << s->et[s->Top + i] << ' ';
        }
    }
}
int main()
{
    Stack s;
    makenull(&s);
    empty(&s);
    fullstack(&s);
    int value;
    cin >> value;
    elemenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        push(A, &s);
    }
    elemenType X;
    top(&s, value);
    pop(&s);
}