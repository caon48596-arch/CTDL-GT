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
        T->ETC = Z;
        T->ET = X;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (T->ETC == '+' || T->ETC == '-' || T->ETC == '/' || T->ETC == '*')
        {
            if (T->right == NULL)
            {
                creat(T->right, X, Z);
            }
            else
            {
                if (T->right->ETC == '+' || T->right->ETC == '-' || T->right->ETC == '/' || T->right->ETC == '*')
                {
                    if (T->right->right == NULL || T->right->left == NULL)
                    {
                        creat(T->right, X, Z);
                    }
                    else
                    {
                        creat(T->left, X, Z);
                    }
                }
                else
                {
                    creat(T->left, X, Z);
                }
            }
        }
    }
}
void xuat(tree T)
{
    if (T != NULL)
    {
        xuat(T->left);
        if (T->ETC == '+' || T->ETC == '-' || T->ETC == '*' || T->ETC == '/')
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
int sum(tree &T)
{
    if (T->ETC != '+' && T->ETC != '-' && T->ETC != '*' && T->ETC != '/')
    {
        return T->ET;
    }
    int right = sum(T->right);
    int left = sum(T->left);
    if (T->ETC == '-')
    {
        return left - right;
    }
    if (T->ETC == '+')
    {
        return left + right;
    }
    if (T->ETC == '-')
    {
        return left * right;
    }
    if (T->ETC == '/')
    {
        return left / right;
    }
}
int main()
{
    tree T;
    MakeNull(T);
    creat(T, 0, '*');
    creat(T, 0, '+');
    creat(T, 6, 'n');
    creat(T, 4, 'n');
    creat(T, 5, 'n');
    xuat(T);
    int kq = sum(T);
    cout << kq;
}