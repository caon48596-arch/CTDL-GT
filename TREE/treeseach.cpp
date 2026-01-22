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
void MakeNull(tree *root)
{
    *root = NULL;
}
tree search(ElemenType X, tree &root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->et == X)
    {
        return root;
    }
    else if (root->et < X)
    {
        return search(X, root->right);
    }
    else
    {
        return search(X, root->left);
    }
}
void insertNode(ElemenType X, tree &root)
{
    if (root == NULL)
    {
        root = new Node;
        root->et = X;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if (X < root->et)
        {
            insertNode(X, root->left);
        }
        else if (X > root->et)
        {
            insertNode(X, root->right);
        }
    }
}
void LNR(tree root)
{
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->et
             << " ";
        LNR(root->right);
    }
}
int main()
{
    tree T;
    MakeNull(&T); // QUAN TRỌNG: Phải khởi tạo cây rỗng trước khi dùng

    // 1. Thêm dữ liệu vào cây
    insertNode(50, T);
    insertNode(30, T);
    insertNode(20, T);
    insertNode(40, T);
    insertNode(70, T);
    insertNode(60, T);
    insertNode(80, T);

    // 2. In cây ra màn hình
    cout << "Duyet cay (tang dan): ";
    LNR(T);
    cout << endl;

    // 3. Test thử chức năng tìm kiếm
    int x = 0;
    tree result = search(x, T);
    if (result != NULL)
    {
        cout << "Tim thay so " << x << " trong cay." << endl;
    }
    else
    {
        cout << "Khong tim thay so " << x << endl;
    }

    return 0;
}