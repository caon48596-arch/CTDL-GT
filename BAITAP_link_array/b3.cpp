#include <bits/stdc++.h>
using namespace std;
#define MAXLEGTH 10
typedef int ElemenType;
typedef int position;
typedef struct arrayy
{
    ElemenType et[MAXLEGTH];
    position last;
} arrayy;
int empty(arrayy *a)
{
    return a->last == 0;
}
int full(arrayy *a)
{
    return a->last == MAXLEGTH;
}
void MakeNull(arrayy *a)
{
    a->last = 0;
}
void nhap(arrayy *a)
{
    cin >> a->last;
    if (a->last < 1 || a->last > MAXLEGTH)
    {
        cout << "sai";
        exit(1);
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
    for (int i = 0; i < a->last; i++)
    {
        cout << a->et[i] << ' ';
    }
}

void sapxep(arrayy *a)
{

    for (int i = 0; i < a->last; i++)
    {
        ElemenType Max = i;
        for (int j = i + 1; j < a->last; j++)
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
    sapxep(&a);
    xuat(&a);
}