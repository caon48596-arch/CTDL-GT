#include <bits/stdc++.h>
using namespace std;
#define MAXLEGTH 5
typedef int ElemenType;
typedef int position;
typedef struct arrayy
{
    ElemenType et[MAXLEGTH];
    position last;
} arrayy;
void MakeNull(arrayy *a)
{
    a->last = 0;
}
int Empty(arrayy *a)
{
    return a->last == 0;
}

int Full(arrayy *a)
{
    return a->last == MAXLEGTH;
}
void nhapvaxuat(arrayy *a)
{
    cin >> a->last;
    if (a->last > 0 && a->last <= MAXLEGTH)
    {
        for (int i = 0; i < a->last; i++)
        {
            cin >> a->et[i];
        }
    }
    else if (a->last > MAXLEGTH)
    {
        cout << "da day";
    }
}
void nhapvaxuatnguoc(arrayy *a)
{
    cin >> a->last;
    if (a->last > 0 && a->last <= MAXLEGTH)
    {
        for (int i = 0; i < a->last; i++)
        {
            cin >> a->et[a->last - 1 - i];
        }
    }
    else if (a->last > MAXLEGTH)
    {
        cout << "da day";
    }
}
void xuat(arrayy *a)
{
    for (int i = 0; i < a->last; i++)
    {
        cout << a->et[i] << ' ';
    }
}
int main()
{
    arrayy a;
    MakeNull(&a);
    Empty(&a);
    nhapvaxuat(&a);
    xuat(&a);

    nhapvaxuatnguoc(&a);
    xuat(&a);
}
