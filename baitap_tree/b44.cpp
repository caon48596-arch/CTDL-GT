#include <bits/stdc++.h>
using namespace std;
typedef char ElemenTypeChar;
typedef struct Node
{
    ElemenTypeChar ETC;
    Node *left;
    Node *right;
} Node;
typedef Node *tree;
void MakeNull(tree &T)
{
    T = NULL;
}
tree Creat(char c)
{
    tree T = new Node;
    T->ETC = c;
    T->left = NULL;
    T->right = NULL;
    return T;
}
void CreatTree(tree &T, char chuoi[])
{
    tree stack[100];
    int top = -1;
    for (int i = 0; chuoi[i] != '\0'; i++)
    {
        char c = chuoi[i];
        if (c >= '0' && c <= '9')
        {
            tree t = Creat(c);
            top++;
            stack[top] = t;
        }
        else
        {
            tree nodecha = Creat(c);
            tree right = stack[top];
            top--;
            tree left = stack[top];
            top--;
            nodecha->left = left;
            nodecha->right = right;
            top++;
            stack[top] = nodecha;
        }
    }
    T = stack[top];
}
void xuat(tree &T)
{
    if (T != NULL)
    {
        xuat(T->left);
        xuat(T->right);
        cout << T->ETC;
    }
}
int sum(tree &T)
{
    if (T->ETC >= '0' && T->ETC <= '9')
    {
        return T->ETC - '0';
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
    if (T->ETC == '*')
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
    char c[100];
    cout << "nhap chuoi ";
    cin.getline(c, 100);
    CreatTree(T, c);
    xuat(T);
    int kq = sum(T);
    cout << kq;
}