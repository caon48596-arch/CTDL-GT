#include <bits/stdc++.h>
using namespace std;

typedef int elemenType;
typedef struct Node
{
    elemenType ET;
    Node *next;
} Node;
typedef Node *position;
typedef struct linkedlist
{
    position header;
    position last;
};
void init(linkedlist *L)
{
    // L = (linkedlist *)malloc(sizeof(linkedlist));
    Node *header = (Node *)malloc(sizeof(Node));
    L->header->next = NULL;
    L->last = L->header;
}
void nhap(linkedlist *L, elemenType value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->ET = value;
    newnode->next = NULL;
    L->last->next = newnode;
    L->last = newnode;
}
void INSERTHEADER(linkedlist *L, elemenType X)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->ET = X;
    // Node *temp = (Node *)malloc(sizeof(Node));
    Node *temp = L->header->next;
    L->header->next = newnode;
    newnode->next = temp;
}
void INSERTTAIL(linkedlist *L, elemenType X)
{
    // Bước 1: Tạo và khởi tạo node mới
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->ET = X;
    newnode->next = NULL;
    if (L->header == NULL)
    {
        L->header = newnode;
    }
    Node *cur = L->header;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newnode;
}
void MIDDLE(linkedlist *L, elemenType X, int index)
{
    if (index < 1)
    {
        printf("Vi tri chen khong hop le (phai >= 1).\n");
        return;
    }
    position prevNode = L->header;
    for (int i = 0; i < index - 1 && prevNode != NULL; i++)
    {
        prevNode = prevNode->next;
    }

    // Bước 3: Kiểm tra xem index có vượt quá độ dài danh sách không
    if (prevNode == NULL)
    {
        printf("Vi tri chen vuot qua do dai danh sách.\n");
        return;
    }

    // Bước 4: Tạo node mới và thực hiện chèn
    // (Đây chính là logic chèn đúng mà bạn đã có sẵn)
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->ET = X;
    newnode->next = prevNode->next;
    prevNode->next = newnode;

    if (newnode->next == NULL)
    {
        L->last = newnode;
    }
}
void xuat(linkedlist *L, elemenType X)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->ET << ' ';
        cur = cur->next;
    }
}
int main()
{
    linkedlist L;
    init(&L);
    elemenType value;
    elemenType X;
    cin >> value;
    elemenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    int V;
    cin >> V;
    // MIDDLE(&L, 15, V);
    INSERTHEADER(&L, 10);
    // INSERTTAIL(&L, 20);
    xuat(&L, X);
}