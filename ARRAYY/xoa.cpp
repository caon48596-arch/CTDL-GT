#include <iostream>
using namespace std;

#define MAXLEGTH 10
typedef int ElementType;
typedef int Position;

typedef struct
{
    ElementType ET[MAXLEGTH];
    Position Last;
} List;

void MAKENULL_LIST(List *L)
{
    L->Last = 0;
}
void EMPTY_LIST(List *L)
{
    L->Last == 0;
}
void DELETE_lIST(Position P, List *L)
{
    if ((P < 1) || (P > L->Last))
    {
        cout << "sai";
    }
    else
    {
        for (Position Q = P; Q < L->Last; Q++)
        {
            L->ET[Q - 1] = L->ET[Q];
        }
        L->Last--;
    }
}
int main()
{
    List L;
    MAKENULL_LIST(&L);
    cin >> L.Last;

    for (int i = 0; i < L.Last; i++)
    {
        cout << "mang [" << i + 1 << "] =";
        cin >> L.ET[i];
    }
    Position A;
    cin >> A;
    DELETE_lIST(A, &L);
    for (int i = 0; i < L.Last; i++)
    {
        cout << "mang [" << i + 1 << "] = " << L.ET[i] << '\n';
    }
}