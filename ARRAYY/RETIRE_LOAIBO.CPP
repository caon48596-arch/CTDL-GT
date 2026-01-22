#include <iostream>
using namespace std;

#define MAX_LENGTH 10

typedef int elementType;
typedef int position;

typedef struct
{
    elementType ET[MAX_LENGTH];
    position last; // số phần tử hiện có
} list;
int MAKENULL_LIST(list *l)
{
    if (l->last = 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void RETIRE(position X, list *l)
{
    for (position Q = 0; Q < l->last; Q++)
    {
        if (l->ET[Q] == X)
        {
            cout << "co " << "vi tri" << Q + 1;
        }
    }
    cout << "k co ";
}

int main()
{
    list l;
    cin >> l.last;
    for (int i = 0; i < l.last; i++)
    {
        cout << "mang[" << i + 1 << "]=";
        cin >> l.ET[i];
    }
    position X;
    cin >> X;
    RETIRE(X, &l);
}