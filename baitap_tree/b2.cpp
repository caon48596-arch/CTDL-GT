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
void MakeNuLL(tree &T)
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
void xuat(tree T)
{
    if (T != NULL)
    {
        cout << T->et << " ";
        xuat(T->left);
        xuat(T->right);
    }
}
void duyet(tree T)
{
    if (T == NULL)
    {
        cout << "k co gia tri";
        return;
    }
    Node *Q[100];
    int front = 0;
    int rear = -1;
    rear++;
    Q[rear] = T;
    cout << "kq duyet theo muc";
    while (front <= rear)
    {
        Node *p = Q[front];
        front++;
        cout << p->et << " ";
        if (p->left != NULL)
        {
            rear++;
            Q[rear] = p->left;
        }

        if (p->right != NULL)
        {
            rear++;
            Q[rear] = p->right;
        }
    }
}
int main()
{
    tree T;
    MakeNuLL(T);
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
    xuat(T);
    duyet(T);
}
