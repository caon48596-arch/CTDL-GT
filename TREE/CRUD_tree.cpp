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
void creat(tree &T, ElemenType X)
{
    if (T == NULL)
    {
        T = new Node;
        T->et = X;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (X > T->et)
        {
            creat(T->right, X);
        }
        else if (X < T->et)
        {
            creat(T->left, X);
        }
    }
}
void Isleaf(tree T)
{
    if (T != NULL)
    {
        if (T->left == NULL && T->right == NULL)
        {
            cout << "T nay la node la";
        }
        else
        {
            Isleaf(T->left);
            Isleaf(T->right);
        }
    }
}
void count(tree T, int &dem)
{

    if (T != NULL)
    {
        dem++;
        count(T->left, dem);
        count(T->right, dem);
    }
}
void seach(tree T, ElemenType X)
{
    if (T == NULL)
    {
        cout << "k thay";
        return;
    }
    if (X == T->et)
    {
        cout << "da thay" << X;
    }
    else
    {
        if (X > T->et)
        {
            seach(T->right, X);
        }
        else if (X < T->et)
        {
            seach(T->left, X);
        }
    }
}
void xuat(tree T)
{
    if (T != NULL)
    {
        cout << T->et << " ";
        xuat(T->left);
        xuat(T->right);
    }
}
int check(tree T, ElemenType X)
{
    if (T == NULL)
    {
        return 0;
    }
    if (X == T->et)
    {
        return 1;
    }
    else
    {
        if (X > T->et)
     
        {
            return check(T->right, X);
        }
        else if (X < T->et)
        {
            return check(T->left, X);
        }
    }
}
void deletemin(tree &T, ElemenType &X)
{
    if (T->left == NULL)
    {
        tree temp = T;
        X = T->et;
        T = T->right;
        delete temp;
    }
    else
    {
        deletemin(T->left, X);
    }
}
void deletenode(tree &T, ElemenType &X)
{
    if (T == NULL)
    {
        cout << "k co gia tri ";
        return;
    }
    if (T != NULL)
    {
        if (T->et < X)
        {
            deletenode(T->right, X);
        }
        else if (T->et > X)
        {
            deletenode(T->left, X);
        }
        else
        {
            // if ((T->left == NULL) && (T->right == NULL))
            // {
            //     T = NULL;
            // }
            // else
            // {
            tree temp = T;
            if (T->right == NULL)
            {
                T = T->left;
                delete temp;
            }
            else if (T->left == NULL)
            {
                T = T->right;
                delete temp;
            }
            else
            {
                ElemenType K;
                deletemin(T->right, K);
                T->et = K;
            }
        }
    }
}
void update(tree &T, ElemenType Z, ElemenType X)
{
    if (check(T, Z) == 0)
    {
        cout << "k co gia tri de thay the";
        return;
    }
    deletenode(T, Z);
    creat(T, X);
}
int main()
{
    tree T;
    MakeNull(T);
    cout << "nhap sl ";
    int value;
    cin >> value;
    ElemenType X;
    for (int i = 0; i < value; i++)
    {
        cin >> X;
        {
            while (check(T, X) == 1)
            {
                cout << "yeu cau nhap lai\n";
                cout << "nhap so ";
                cin >> X;
            }
        }
        creat(T, X);
    }
    xuat(T);
    ElemenType A;
    cout << " \nnhap so can tim \n";
    cin >> A;
    seach(T, A);
    cout << "\nnhap so can xoa\n";
    ElemenType S;
    cin >> S;
    deletenode(T, S);
    xuat(T);
    int dem = 0;
    cout << "\ntong cac node la\n";
    count(T, dem);
    cout << dem;
    cout << "doi gia tri ";
    ElemenType D;
    cin >> D;
    ElemenType Z;
    cin >> Z;
    update(T, D, Z);
    xuat(T);
    return 0;
}
