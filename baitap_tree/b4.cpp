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
    }
}
int sum(tree T)
{
    if (T->ETC != '+' && T->ETC != '-' && T->ETC != '*' && T->ETC != '/')
    {
        return T->ET;
    }
    int left = sum(T->left);
    int right = sum(T->right);
    if (T->ETC == '+')
    {
        return left + right;
    }
    else if (T->ETC == '-')
    {
        return left - right;
    }
    else if (T->ETC == '*')
    {
        return left * right;
    }
    else if (T->ETC == '/')
    {
        return left / right;
    }
}
void xuat(tree T)
{
    if (T != NULL)
    {
        xuat(T->left);
        xuat(T->right);
        if (T->ETC == '+' || T->ETC == '-' || T->ETC == '*' || T->ETC == '/')
        {
            cout << T->ETC << " ";
        }
        else
        {
            cout << T->ET << " ";
        }
    }
}
int main()
{
    tree T;
    MakeNull(T);
    ElemenType A;
    creat(T, 6, 'n');
    creat(T, 4, 'n');
    creat(T, 5, 'n');
    creat(T, 0, '*');
    creat(T, 0, '+');
    // xuat(T);
    int kq = sum(T);
    cout << "\n"
         << kq;
}