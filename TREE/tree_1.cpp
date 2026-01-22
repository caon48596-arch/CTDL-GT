#include <bits/stdc++.h>
using namespace std;
typedef int ElemenType;
typedef struct Tode
{
    ElemenType et;
    Tode *left;
    Tode *right;
} Tode;
typedef Tode *Tree;
void MakeTull(Tree *T)
{
    *T = NULL;
}
int Empty(Tree T)
{
    return T == NULL;
}
Tree LeftChild(Tree n)
{
    if (n != NULL)
    {
        return n->left;
    }
    else
    {
        return NULL;
    }
}
Tree RigtChild(Tree n)
{
    if (n != NULL)
    {
        return n->right;
    }
    else
    {
        return NULL;
    }
}
int IsLeaf(Tree n)
{
    if (n != NULL)
    {
        return (LeftChild(n) == NULL) && (RigtChild(n) == NULL);
    }
    else
    {
        return 0;
    }
}
int TB_TODES(Tree T)
{
    if (Empty(T))
    {
        return 0;
    }
    else
    {
        return 1 + TB_TODES(LeftChild(T)) + TB_TODES(RigtChild(T));
    }
}
void Create2(Tree &T, ElemenType X)
{
    // Tree T;
    if (T == NULL)
    {
        T = new Tode;
        (T)->et = X;
        (T)->left = NULL;
        (T)->right = NULL;
    }
    else if (X < (T)->et)
    {
        Create2((T)->left, X);
    }
    else if (X > (T)->et)
    {
        Create2((T)->right, X);
    }
}
void PreOrder(Tree T)
{
    if (T != NULL)
    {
        cout << T->et;
        PreOrder(LeftChild(T));
        PreOrder(RigtChild(T));
    }
}
int main()
{
    Tree T;
    MakeTull(&T);
    cout << "so sl gia tri ";
    int value;
    cin >> value;
    ElemenType A;
    for (int i = 0; i < value; i++)
    {
        cout << "nhap so ";
        cin >> A;
        Create2(T, A);
    }
    cout << "So nut: " << TB_TODES(T) << endl;
    PreOrder(T);
    return 0;
}