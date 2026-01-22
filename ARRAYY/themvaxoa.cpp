#include <iostream>

using namespace std;
#define maxlegth 10
typedef int elementTpe;
typedef int position;

typedef struct
{
    elementTpe ET[10];
    position last;
} list;
void makenull(list *l)
{
    l->last = 0;
}
void INSERT(elementTpe X, position P, list *l)
{
    if (l->last == maxlegth)
    {
        cout << "sai";
    }
    else if ((P > 1) || (P > l->last))
    {
        position Q;
        for (Q = l->last; P <= Q; Q--)
        {
            l->ET[Q] = l->ET[Q - 1];
        }
        l->ET[P - 1] = X;
        l->last++;
    }
}
void DELETE(position P, list *l)
{
    for (position A = P; A < l->last; A++)
    {
        l->ET[A - 1] = l->ET[A];
    }
    l->last--;
}

int main()
{
    list l;
    makenull(&l);
    cout << "nhap sl ";
    cin >> l.last;
    elementTpe X;
    cout << "nhap gtri ";
    cin >> X;
    position P;
    cout << "vitri ";
    cin >> P;
    for (int i = 0; i < l.last; i++)
    {
        cout << "mag[" << i + 1 << "] = ";
        cin >> l.ET[i];
    }
    cout << "\n";
    INSERT(X, P, &l);
    for (int i = 0; i < l.last; i++)
    {
        cout << "mag[" << i + 1 << "] = " << l.ET[i] << "\n";
    }
    cout << " ";
    elementTpe A;
    cout << "nhap vi tri";
    cin >> A;
    DELETE(A, &l);

    for (int i = 0; i < l.last; i++)
    {
        cout << "mag[" << i + 1 << "] = " << l.ET[i] << "\n";
    }
}