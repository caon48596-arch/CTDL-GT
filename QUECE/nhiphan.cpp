#include <bits/stdc++.h>
using namespace std;

typedef int ElemenType;
struct Node
{
    ElemenType et;
    Node *next;
    Node *previous;
};
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
int Empty(linkedlist *L)
{
    return L->header == NULL;
}
void INSERTHEADER(linkedlist *L, ElemenType X)
{
    position newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    if (L->header->next == NULL)
    {
        newnode->next = NULL;
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
void MID(linkedlist *L, int value, ElemenType X)
{
    Node *prev = (Node *)malloc(sizeof(Node));
    prev = L->header;
    for (int i = 0; i < value && prev != NULL; i++)
    {
        prev = prev->next;
    }
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = prev->previous;
    temp->next = newnode;
    newnode->next = prev;
    prev->previous = newnode;
    newnode->previous = temp;
}
void Print(linkedlist *L)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    linkedlist L;
    MakeNull(&L);
    // Empty(&L);
    INSERTHEADER(&L, 10);
    INSERTHEADER(&L, 20);
    INSERTHEADER(&L, 30);
    INSERTHEADER(&L, 40);
    MID(&L, 2, 50);
    Print(&L);

    return 0;
}