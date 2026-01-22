#include <bits/stdc++.h>
using namespace std;
#define MAXLEGTH 10
typedef int ElemenType;
typedef int position;
typedef struct Node
{
    ElemenType et[MAXLEGTH];
    position last;
} arrayy;
void MakeNull(arrayy *a)
{
    a->last = -1;
}
void Empty(arrayy *a)
{
    a->last == -1;
}
int Full(arrayy *a)
{
    return a->last == MAXLEGTH;
}
void nhap(arrayy *a)
{
    cin >> a->last;
    if (Full(a))
    {
        cout << "day";
    }
    else
    {
        for (int i = 0; i < a->last; i++)
        {
            cin >> a->et[i];
        }
    }
}
void xuat(arrayy *a)
{

    if (Full(a))
    {
        cout << "day";
    }
    else
    {
        for (int i = 0; i <= a->last; i++)
        {
            cout << a->et[i] << ' ';
        }
    }
}

void themvasapxep(arrayy *a)
{
    position X;
    cin >> X;
    ElemenType A;
    cin >> A;
    for (int i = a->last; i >= X; i--)
    {
        if (X == i)
        {
            a->et[i] = A;
        }
        else
        {
            a->et[i] = a->et[i - 1];
        }
    }
    for (int i = 0; i <= a->last; i++)
    {
        ElemenType Max = i;
        for (int j = i + 1; j <= a->last; j++)
        {
            if (a->et[Max] < a->et[j])
            {
                Max = j;
            }
        }
        ElemenType temp = a->et[i];
        a->et[i] = a->et[Max];
        a->et[Max] = temp;
    }
}

int main()
{
    arrayy a;
    MakeNull(&a);
    nhap(&a);
    themvasapxep(&a);
    xuat(&a);
}