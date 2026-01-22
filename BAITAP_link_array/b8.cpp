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
int MakeNull(arrayy *A)
{
    return A->last = 0;
}
int Full(arrayy *A)
{
    return A->last == MAXLEGTH;
}
int check(arrayy *A, ElemenType n)
{
    for (int i = 0; i < A->last; i++)
    {
        if (A->et[i] == n)
        {
            return 1;
        }
    }
    return 0;
}
void nhap(arrayy *A)
{
    cout << "nhap sl ";
    int S;
    cin >> S;
    ElemenType n;
    int temp;
    for (int i = 0; i < S; i++)
    {

        cin >> n;
        while (check(A, n) == 1)
        {
            cout << "yeu cau nhap lai";
            cin >> n;
        }
        temp = i;
        for (int j = 0; j <= A->last; j++)
        {
            if (A->et[j] > n)
            {
                temp = j;
                break;
            }
        }
        for (int c = i; c > temp; c--)
        {
            A->et[c] = A->et[c - 1];
        }
        A->et[temp] = n;
        A->last++;
    }
}
void xuat(arrayy *A)
{
    for (int i = 0; i < A->last; i++)
    {
        cout << A->et[i] << " ";
    }
}
int main()
{
    arrayy A;
    MakeNull(&A);
    nhap(&A);
    xuat(&A);
}