#include <bits/stdc++.h>
using namespace std;
#define MAXLEGTH 10
typedef int ElemenType;
typedef int jition;
typedef struct arrayy
{
    ElemenType et[MAXLEGTH];
    jition last;
} arrayy;
void MakeNull(arrayy *A)
{
    A->last = -1;
}
int Full(arrayy *A)
{
    return A->last == MAXLEGTH;
}
void xuat(arrayy *A)
{
    int S;
    for (int i = 0; i < S; i++)
    {
        cout << A->et[i] << " ";
    }
}
void chen(arrayy *A)
{
    ElemenType X;
    ElemenType S;
    cin >> S;
    int temp;
    for (int i = 0; i < S; i++)
    {
        cin >> X;
        for (int j = 0; j <= i; j++)
        {
            if (A->et[j] > X)
            {
                temp = j;
                break;
            }
        }
        for (int c = i; c > temp; c--)
        {
            A->et[c] = A->et[c - 1];
        }
        A->et[temp] = X;
    }
}

int main()
{
    arrayy A;
    MakeNull(&A);
    chen(&A);
    xuat(&A);
}