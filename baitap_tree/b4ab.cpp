#include <bits/stdc++.h>
using namespace std;
typedef int ElemenType;
typedef char ElemenTypeChar;
typedef struct Node
{
    ElemenType ET;
    ElemenTypeChar ETC;
    Node *left;
    Node *right;
} Node;
typedef Node *tree;
void MakeNull(tree &T)
{
    T = NULL;
}
void creat(tree &T, ElemenType X, ElemenTypeChar Z)
{
    if (T == NULL)
    {
        T = new Node;
        T->ET = X;
        T->ETC = Z;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (T->ETC == '+' || T->ETC == '-' || T->ETC == '*' || T->ETC == '/')
        {

            if (T->left == NULL)
            {
                creat(T->left, X, Z);
            }
            else
            {
                if (T->left->ETC == '+' || T->left->ETC == '-' || T->left->ETC == '*' || T->left->ETC == '/')
                {
                    if (T->left->left == NULL || T->left->right == NULL)
                    {
                        creat(T->left, X, Z);
                    }
                    else
                    {
                        creat(T->right, X, Z);
                    }
                }
                else
                {
                    creat(T->right, X, Z);
                }
            }
        }
        // else
        // {
        //     // Nếu T không phải toán tử (Tức là T là số), không làm gì cả
        //     // (Vì số là node lá)
        // }
    }
}

int tinhToan(tree T)
{
    if (T == NULL)
        return 0;

    if (T->ETC != '+' && T->ETC != '-' && T->ETC != '*' && T->ETC != '/')
    {
        return T->ET;
    }
    // Nếu là dấu, tính toán đệ quy 2 bên
    int trai = tinhToan(T->left);
    int phai = tinhToan(T->right);

    // Thực hiện phép tính
    if (T->ETC == '+')
        return trai + phai;
    if (T->ETC == '-')
        return trai - phai;
    if (T->ETC == '*')
        return trai * phai;
    if (T->ETC == '/')
        return trai / phai;

    return 0;
}
void xuat(tree T)
{
    if (T != NULL)
    {
        xuat(T->left);
        if (T->ETC == '+' || T->ETC == '-' || T->ETC == '/' || T->ETC == '*')
        {
            cout << T->ETC << " ";
        }
        else
        {
            cout << T->ET << " ";
        }
        xuat(T->right);
    }
}
int main()
{
    tree T;
    MakeNull(T);
    creat(T, 0, '*'); // 1. Gốc *
    creat(T, 0, '+'); // 2. Dấu + (Vào bên trái *)
    creat(T, 6, 'n'); // 3. Số 6 (Vào bên trái +)
    creat(T, 4, 'n'); // 4. Số 4 (Vào bên phải +)
    creat(T, 5, 'n');
    xuat(T);
    int kq = tinhToan(T);
    cout << kq;
}
