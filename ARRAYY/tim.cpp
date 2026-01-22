#include <iostream>
using namespace std;

#define maxlegth 10
typedef int elementType;
typedef int position;

typedef struct
{
    elementType ET[maxlegth];
    position last;
} list;
void location(elementType X, position P, list *l)
{
    P = 1;
    while (P != l->last + 1)
    {
        if (l->ET[P - 1] == X)
        {
            cout << "vitri " << X << "la" << P;
            break;
        }
        else
        {
            P++;
        }
    }
}
int main()
{
    list l;
    cin >> l.last;
    for (int i = 0; i < l.last; i++)
    {
        cout << "mag[" << i + 1 << "] = ";
        cin >> l.ET[i];
    }
    elementType X;
    cin >> X;
    position P;
    location(X, P, &l);
}