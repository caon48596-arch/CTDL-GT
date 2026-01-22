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
    L->header->previous - NULL;
    L->last = L->header;
}
void Empty(linkedlist *L)
{
    L->header == NULL;
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
        Node *temp = (Node *)malloc(sizeof(Node));
        temp = L->header->next;
        L->header->next = newnode;
        newnode->next = temp;
        temp->previous = newnode;
        newnode->previous = L->header;
    }
}
void sapxep(linkedlist *L)
{
    for (Node *i = L->header->next; i != NULL; i = i->next)
    {
        Node *A = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (A->et < j->et)
            {
                A = j;
            }
        }
        int temp = i->et;
        i->et = A->et;
        A->et = temp;
    }
}
void xuat(linkedlist *L)
{
    Node *cur = L->last;
    while (cur != L->header)
    {
        cout << cur->et << ' ';
        cur = cur->previous;
    }
}
int main()
{
    linkedlist L;
    MakeNull(&L);
    Empty(&L);
    int value;
    cin >> value;
    ElemenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    // sapxep(&L);
    xuat(&L);
}