#include <bits/stdc++.h>
using namespace std;
typedef int ElemenType;
typedef struct Node
{
    ElemenType et;
    Node *next;
    Node *previous;
} Node;
typedef Node *position;
typedef struct linkedlist
{
    position header;
    position last;
} linkedlist;
void MakeNull(linkedlist *L)
{
    L->header = (Node *)malloc(sizeof(Node));
    L->header->next = NULL;
    L->header->previous = NULL;
    L->last = L->header;
}
void nhap(linkedlist *L, ElemenType X)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->previous = NULL;
    newnode->et = X;
    if (L->header->next == NULL)
    {
        L->header->next = newnode;
        newnode->previous = L->header;
        L->last = newnode;
    }
    else
    {
        L->last->next = newnode;
        newnode->previous = L->last;
        L->last = newnode;
    }
}
void xuatnguoc(linkedlist *L)
{
    Node *cur = L->last;
    while (cur != L->header)
    {
        cout << cur->et << ' ';
        cur = cur->previous;
    }
}
void xuat(linkedlist *L)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << ' ';
        cur = cur->next;
    }
}
int main()
{
    linkedlist L;
    MakeNull(&L);
    int value;
    cin >> value;
    ElemenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    xuat(&L);
    cout << ' ';
    xuatnguoc(&L);
}