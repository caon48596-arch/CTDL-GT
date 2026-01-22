#include <bits\stdc++.h>
using namespace std;
#define MAXLEGTH 10
typedef char elemenType;
typedef struct
{
    elemenType et[10];
    int Top;
} Stack;

void pusp(Stack *s, elemenType X)
{
    if (s->Top != 0)
    {
        s->Top = s->Top - 1;
        s->et[s->Top] = X;
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
void move(int value, char A, char B, char C)
{
    if (value == 1)
    {
        cout << "chuyen 1 dia tu " << A << " sang " << C << "\n";
    }
    else
    {
        move(value - 1, A, B, C);
        move(1, A, C, B);
        move(value - 1, B, A, C);
    }
}
void makenull(Stack *s)
{
    s->Top = MAXLEGTH;
}
int main()
{
    Stack s;
    makenull(&s);
    // empty(&s);
    // fullstack(&s);
    int value;
    cin >> value;
    // elemenType A;
    // for (int i = 0; i < value; i++)
    // {
    //     cin >> A;
    //     pusp(&s, A);
    // }
    // top(&s, value);
    printf("\nCac buoc di chuyen cho %d dia:\n", value);

    move(value, 'a', 'b', 'c');
}