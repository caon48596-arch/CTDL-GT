#include <bits/stdc++.h>
using namespace std;
typedef char ElemenTypeChar;
typedef struct Node
{
    ElemenTypeChar etc;
    Node *left;
    Node *right;
} Node;
typedef Node *tree;
void MakeNull(tree &T)
{
    T = NULL;
}
tree creat(ElemenTypeChar X)
{
    tree T = new Node;
    T->etc = X;
    T->left = NULL;
    T->right = NULL;
    return T;
}
void creatchild(tree &T, tree T1, tree T2, tree T3, ElemenTypeChar A)
{
    if (T == NULL)
    {
        T = creat('A');
    }
    if (T->left == NULL)
    {
        T1 = creat('c');
        T->left = T1;
    }
    if (T1 != NULL)
    {
        T2 = creat('s');
        T1->right = T2;
    }
    if (T2 != NULL)
    {
        T3 = creat('q');
        T2->right = T3;
    }
}
void XuatCay(tree T)
{
    if (T != NULL)
    {
        cout << "|-- " << T->etc << endl;
        XuatCay(T->left);
        XuatCay(T->right);
    }
}
void count(tree T, int &dem)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        dem++;
        count(T->left, dem);
        count(T->right, dem);
    }
}
void checkleaf(tree &T)
{
    if (T->left == NULL)
    {
        cout << T->etc << " la node la\n";
    }
    else
    {
        checkleaf(T->left);
    }
    checkleaf(T->right);
}
int main()
{
    tree T, T1, T2, T3;
    MakeNull(T);
    ElemenTypeChar A;
    creatchild(T, T1, T2, T3, A);
    XuatCay(T);

    // creatchild(T, '2');
    // creatchild(T->left, '3');
    // creatchild(T->left, '4');
    // creatchild(T->left->left, '6');
    // creatchild(T->left->left, '7');
    // creatchild(T, '2');
    // creatchild(T->left, '5');
    int dem = 0;
    count(T, dem);
    cout << dem << "\n";
    checkleaf(T);
}