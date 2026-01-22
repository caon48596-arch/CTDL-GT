#include <iostream>
using namespace std;

#define MAX_LENGTH 10

typedef int elementType;
typedef char position;

typedef struct
{
    elementType ET[MAX_LENGTH];
    position last;
} list;
void makenull(list *l)
{
    l->last = 0;
}
void FIX(position X, elementType P, list *l)
{
    for (position A = 1; A <= l->last; A++)
    {
        if (X == A)
        {
            l->ET[A] = P;
        }
    }
}

int main()
{
    list l;
    makenull(&l);
    fgets(l.last, sizeof(l.last), stdin);
    position X;
    elementType P;
    cin >> X;
    cin >> P;
    FIX(X, P, &l);
    for (int i = 1; i <= l.last; i++)
    {
        cout << "mag[" << i << "] = " << l.ET[i] << "\n";
    }
    return 0;
}