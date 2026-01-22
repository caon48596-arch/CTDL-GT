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
    L->header = new Node;
    L->header->next = NULL;
    L->header->previous = NULL;
    L->last = L->header;
}
void nhap(linkedlist *L)
{
    cout << "nhap sl ";
    ElemenType S;
    cin >> S;
    ElemenType A;
    for (int i = 0; i < S; i++)
    {
        cin >> A;
        Node *newnode = new Node;
        newnode->next = NULL;
        newnode->previous = NULL;
        newnode->et = A;
        L->last->next = newnode;
        newnode->previous = L->last;
        L->last = newnode;
    }
}
void check(linkedlist *L)
{
    Node *limit = L->last;
    for (Node *i = L->header->next; i != limit->next; i = i->next)
    {
        if (i->et % 2 != 0)
        {
            Node *newnode = new Node;
            newnode->next = NULL;
            newnode->previous = NULL;
            newnode->et = i->et;
            L->last->next = newnode;
            newnode->previous = L->last;
            L->last = newnode;
        }
    }
    Node *cur = L->header->next;
    while (cur != NULL && cur != limit->next)
    {
        if (cur->et % 2 != 0)
        {
            cout << cur->et << " ";
        }
        cur = cur->next;
    }
}
int main()
{
    linkedlist L;
    MakeNull(&L);
    nhap(&L);
    cout << "\n";
    check(&L);
}
