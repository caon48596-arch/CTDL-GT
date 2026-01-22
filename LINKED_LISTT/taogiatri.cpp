#include <bits/stdc++.h>
using namespace std;

typedef int elemenType;
typedef struct Node
{
    elemenType ET;
    Node *next;
};
typedef Node *position;
typedef struct linkedlist
{
    position header;
    position last;
};

void khoitao(linkedlist &L)
{
    L.header = (Node *)malloc(sizeof(Node));
    L.header->next = NULL;
    L.last = L.header;
}
void nhap(linkedlist &L, elemenType value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->ET = value;
    newnode->next = NULL;
    L.last->next = newnode;
    L.last = newnode;
}
void xuat(linkedlist &L, elemenType X)
{
    Node *cur = L.header->next;
    while (cur != NULL)
    {
        cout << cur->ET;
        cur = cur->next;
    }
}
int main()
{
    linkedlist L;
    khoitao(L);
    elemenType value;
    elemenType X;
    cin >> value;
    elemenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(L, A);
    }
    xuat(L, X);
}