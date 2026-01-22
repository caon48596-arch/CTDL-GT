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
void MakeNull(arrayy *A)
{
    A->last = -1;
}
void Empty(arrayy *A)
{
    A->last == -1;
}
int Full(arrayy *A)
{
    return A->last == MAXLEGTH;
}
void nhap(arrayy *A)
{
    cin >> A->last;
    if (A->last < 1 || A->last > MAXLEGTH)
    {
        cout << "sai";
        exit(1);
    }
    else
    {
        for (int i = 0; i < A->last; i++)
        {
            cin >> A->et[i];
        }
    }
}
void xuat(arrayy *A)
{
    for (int i = 0; i < A->last; i++)
    {
        cout << A->et[i] << " ";
    }
}

void seachandelete(arrayy *A)
{
    ElemenType X;
    cin >> X;
    int temp = 0;
    int vitri;
    int i;
    for (i = 0; i < A->last; i++)
    {
        if (X == A->et[i])
        {
            temp = 1;
            vitri = i;
        }
    }
    if (temp == 1)
    {
        cout << "co" << vitri << " " << X;
    }
    else
    {
        cout << "khong";
        return;
    }
    cout << "\n";
    for (int i = A->last - 1; i > vitri; i--)
    {
        A->et[i - 1] = A->et[i];
    }
    A->last--;
}
int main()
{
    arrayy A;
    MakeNull(&A);
    nhap(&A);
    seachandelete(&A);
    xuat(&A);
}
