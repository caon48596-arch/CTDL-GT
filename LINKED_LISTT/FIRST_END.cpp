#include <bits\stdc++.h>
using namespace std;
typedef int elemenType;
typedef struct Node
{
    elemenType et;
    Node *next;
} Node;
typedef Node *position;
typedef struct linkedlist
{
    position header;
    position last;
} linkedlist;
void init(linkedlist *L)
{
    Node *header = (Node *)malloc(sizeof(Node));
    L->header->next = NULL;
    L->last = L->header;
}
void nhap(linkedlist *L, elemenType X)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    newnode->next = NULL;
    L->last->next = newnode;
    L->last = newnode;
}
void xuat(linkedlist *L, elemenType X)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << ' ';
        cur = cur->next;
    }
}
void FIRST(linkedlist *L)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode = L->header;
    if (newnode == NULL)
    {
        cout << "k co gia tri dau";
    }
    else
    {
        cout << newnode->next->et << " la gia tri dau";
    }
}
void END(linkedlist *L)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode = L->last;
    if (newnode == NULL)
    {
        cout << "sai";
    }
    else
    {
        cout << "gia tri cuoi la " << newnode->et;
    }
}
int main()
{
    linkedlist L;
    init(&L);
    cout << "nhap sl ";
    int value;
    cin >> value;
    elemenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    xuat(&L, A);
    FIRST(&L);
    END(&L);
}