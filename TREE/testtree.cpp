#include <bits/stdc++.h>
using namespace std;
typedef int ElemenType;
typedef struct Node
{
    ElemenType et;
    Node *left;
    Node *right;
} Node;
typedef Node *tree;
void MakeNull(tree &T)
{
    T = NULL;
}
void creat(tree &T, ElemenType A)
{
    if (T == NULL)
    {
        T = new Node;
        T->et = A;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (A > T->et)
        {
            creat(T->right, A);
        }
        else if (A < T->et)
        {
            creat(T->left, A);
        }
    }
}
void Xuat(tree T)
{
    if (T != NULL)
    {
        cout << T->et << " ";
        Xuat(T->left);
        Xuat(T->right);
    }
}
void DeleteMin(tree &T, ElemenType &X)
{
    if (T->left == NULL)
    {
        tree temp = T;
        X = T->et;
        T = T->right;
    }
    else
    {
        DeleteMin(T->left, X);
    }
}
void DeleteNode(ElemenType X, tree &T)
{
    if (T != NULL)
    {
        if (X < T->et)
            DeleteNode(X, T->left);
        else if (X > T->et)
            DeleteNode(X, T->right);
        else
        {
            tree temp = T;
            if (T->left == NULL)
            {
                T = T->right;
            }
            else if (T->right == NULL)
            {
                T = T->left;
            }
            else
            {
                DeleteMin(T->right, T->et);
            }
        }
    }
}
void seach(tree &T, ElemenType X)
{
    if (T == NULL)
    {
        cout << "k thay";
        return;
    }
    if (X == T->et)
    {
        cout << "da tim thay";
    }
    else if (X > T->et)
    {
        seach(T->right, X);
    }
    else if (X < T->et)
    {
        seach(T->left, X);
    }
}

void chen(tree &T, ElemenType A)
{
    if (T == NULL)
    {
        Node *T = new Node;
        T->et = A;
        T->right = NULL;
        T->left = NULL;
    }
    else
    {
        if (A > T->et)
        {
            chen(T->right, A);
        }
        else if (A < T->et)
        {
            chen(T->left, A);
        }
    }
}
int main()
{
    tree T;
    MakeNull(T);
    cout << "nhap sl ";
    int value;
    cin >> value;
    ElemenType A;
    for (int i = 0; i < value; i++)
    {
        cout << "nhap so ";
        cin >> A;
        creat(T, A);
    }
    Xuat(T);
    ElemenType X;
    cout << "\n";
    cout << "nhap X ";
    cin >> X;
    seach(T, X);
    chen(T, 10);
    Xuat(T);
    ElemenType a;
    cout << "\n\nNhap gia tri can xoa: ";
    cin >> a;
    DeleteNode(a, T);
    Xuat(T);
}