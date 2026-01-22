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
    ElemenType A;
    cin >> A;
    ElemenType S;
    for (int i = 0; i < A; i++)
    {
        cin >> S;
        Node *newnode = new Node;
        newnode->et = S;
        newnode->next = NULL;
        newnode->previous = NULL;
        L->last->next = newnode;
        newnode->previous = L->last;
        L->last = newnode;
    }
    // Node *cur = new Node;
    // cur = L->header->next;
    // while (cur != NULL)
    // {
    //     cout << cur->et << " ";
    //     cur = cur->next;
    // }
}
void check(linkedlist *L, linkedlist *l1, linkedlist *l2)
{
    Node *limit = L->last;
    for (Node *i = L->header->next; i != limit->next; i = i->next)
    {
        if (i->et % 2 != 0)
        {
            Node *newnode = new Node;
            newnode->et = i->et;
            newnode->next = NULL;
            newnode->previous = NULL;
            l1->last->next = newnode;
            newnode->previous = l1->last;
            l1->last = newnode;
        }
        else
        {
            Node *newnode = new Node;
            newnode->et = i->et;
            newnode->next = NULL;
            newnode->previous = NULL;
            l2->last->next = newnode;
            newnode->previous = l2->last;
            l2->last = newnode;
        }
    }
    Node *cur = l1->header->next;
    while (cur != NULL)
    {
        cout << cur->et << " ";
        cur = cur->next;
    }
    cout << "\n";
    Node *cur1 = l2->header->next;
    while (cur1 != NULL)
    {
        cout << cur1->et << " ";
        cur1 = cur1->next;
    }
}
int main()
{
    linkedlist L, sole, sochan;
    MakeNull(&L);
    MakeNull(&sole);
    MakeNull(&sochan);
    nhap(&L);
    check(&L, &sole, &sochan);
}