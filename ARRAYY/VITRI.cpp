#include <iostream>
using namespace std;

#define MAX_LENGTH 10
typedef float elementType;
typedef int position;
// ViTri 1 2

typedef struct
{
    elementType a[MAX_LENGTH];
    position last;
} list;

void MAKENULL_LIST(list *L)
{
    L->last = 0;
}

// Hàm kiểm tra danh sách có rỗng ko
int EMPTY_LIST(list *L)
{
    if (L->last == 0)
    {
        return 1;
    }
    return 0;
}

void INSERT_LIST(elementType X, position P, list *L)
{
    if (L->last == MAX_LENGTH)
    {
        cout << "day";
    }
    else if ((P < 1) || (P > L->last + 1))
    {
        cout << "vi tri sai";
    }
    else
    {
        for (position Q = L->last; Q >= P - 1; Q--)
        {
            L->a[Q] = L->a[Q - 1];
        }

        L->a[P - 1] = X;
        L->last++;
    }
}

int main()
{
    list L;
    MAKENULL_LIST(&L);
    // EMPTY_LIST(&L);
    cin >> L.last;
    for (int i = 0; i < L.last; i++)
    {
        cout << "mang[" << i + 1 << "] = ";
        cin >> L.a[i];
    }
    cout << "gia tri";
    elementType X;
    cin >> X;
    cout << "vi tri";
    position P;
    cin >> P;
    INSERT_LIST(X, P, &L);
    cout << "Phan tu thuoc danh sach:\n";

    for (int i = 0; i < L.last; i++)
    {
        cout << "mang[" << i + 1 << "] = " << L.a[i] << '\n';
    }
    cout << endl;
}