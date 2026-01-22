#include <bits\stdc++.h>
using namespace std;
typedef int elmenType;
typedef struct Node
{
    elmenType et;
    Node *next;
} Node;
typedef Node *position;
typedef struct linkedlist
{
    position header;
    position last;
} linkedlist;
void makenull(linkedlist *L)
{
    L->header = 0;
}
void empty(linkedlist *L)
{
    L->header == 0;
    return;
}
void init(linkedlist *L)
{
    L->header = (Node *)malloc(sizeof(Node));
    L->header->next = NULL;
    L->last = L->header;
}
void nhap(linkedlist *L, elmenType X)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    newnode->next = NULL;
    L->last->next = newnode;

    L->last = newnode;
}
void xuat(linkedlist *L, elmenType X)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << ' ';
        cur = cur->next;
    }
}
void local(linkedlist *L, int index, int value)
{
    Node *cur = (Node *)malloc(sizeof(Node));
    cur = L->header->next;
    for (int i = 1; i <= value && cur != NULL; cur = cur->next, i++)
    {
        // if (index > cur->et)
        // {
        //     cout << "sai";
        //     exit(1);
        // }
        if (cur->et == index)
        {
            cout << "dung vi tri" << i << ' ' << cur->et;
        }
    }
}
int main()
{
    linkedlist L;
    makenull(&L);
    empty(&L);
    cout << "nhap sl ";
    int value;
    cin >> value;
    init(&L);
    elmenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    elmenType X;
    xuat(&L, X);
    int Z;
    cin >> Z;
    local(&L, Z, value);
}
