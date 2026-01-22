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
void linklist1(linkedlist *L, ElemenType value)
{
    // cin >> value;
    ElemenType A;
    for (int i = 0; i < value; i++)
    {

        cout << "nhap so ";
        cin >> A;
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->next = NULL;
        newnode->previous = NULL;
        newnode->et = A;
        if (L->header->next == NULL)
        {
            L->header->next = newnode;
            newnode->previous = L->header;
            L->last = newnode;
        }
        else
        {
            while (A < L->header->next->et)
            {
                cout << "yeu cau nhap lai ";
                cin >> A;
            }
            Node *newnode2 = (Node *)malloc(sizeof(Node));
            newnode2->et = A;
            newnode2->next = NULL;
            newnode2->previous = NULL;
            L->last->next = newnode2;
            newnode2->previous = L->last;
            L->last = newnode2;
        }
    }
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << " ";
        cur = cur->next;
    }
    cout << "\n";
}
void pluss(linkedlist *L1, linkedlist *L2, linkedlist *L3)
{
    Node *cur1 = L1->header->next;
    Node *cur2 = L2->header->next;
    while (cur1 != NULL && cur2 != NULL)
    {
        Node *cur3 = (Node *)malloc(sizeof(Node));
        cur3->next = NULL;
        if (cur1->et < cur2->et)
        {
            cur3->et = cur1->et;
            cur1 = cur1->next;
        }
        else
        {
            cur3->et = cur2->et;
            cur2 = cur2->next;
        }
        L3->last->next = cur3;
        cur3->previous = L3->last;
        L3->last = cur3;
    }
    while (cur1 != NULL)
    {
        Node *cur3 = (Node *)malloc(sizeof(Node));
        cur3->next = NULL;
        cur3->et = cur1->et;
        cur1 = cur1->next;

    L3->last->next = cur3;
    cur3->previous = L3->last;
    L3->last = cur3;
    }

    while (cur2 != NULL)
    {
        Node *cur3 = (Node *)malloc(sizeof(Node));
        cur3->next = NULL;
        cur3->et = cur2->et;
        cur2 = cur2->next;

        L3->last->next = cur3;
        cur3->previous = L3->last;
        L3->last = cur3;
    }

    Node *cur = L3->header->next;
    while (cur != NULL)
    {
        cout << cur->et << " ";
        cur = cur->next;
    }
    cout << "\n";
}
int main()
{
    linkedlist L1, L2, L3;
    MakeNull(&L1);
    MakeNull(&L2);
    MakeNull(&L3);
    linklist1(&L1, 3);
    linklist1(&L2, 3);
    pluss(&L1, &L2, &L3);
}