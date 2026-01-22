#include <iostream>
using namespace std;

#define MAX_LENGTH 10

typedef int elementType;
typedef int position;

typedef struct
{
    elementType ET[MAX_LENGTH];
    position last;
} list;
void makenull(list *l)
{
    l->last = 0;
}
void next(position X, list *l)
{
    if (X > l->last || X < 1)
    {
        cout << "sai";
    }
    else
    {
        cout << X + 1 << "vitri " << l->ET[X + 1];
    }
}

int main()
{
    list l;
    makenull(&l);
    int n;
    cin >> n;
    l.last = n;
    for (int i = 1; i <= l.last; i++)
    {
        cout << "mag[" << i << "] = ";
        cin >> l.ET[i];
    }
    position X;
    cin >> X;
    next(X, &l);
    return 0;
}