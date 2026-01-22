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
    L->last->next = newnode;
    newnode->previous = L->last;
    L->last = newnode;
}
void xuat(linkedlist *L)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << " ";
        cur = cur->next;
    }
}
void gop(linkedlist *L)
{
    for (Node *i = L->header->next; i != NULL; i = i->next)
    {
        Node *seach = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            seach = seach->next;
            if (i->et == j->et)
            {
                if (seach->next != NULL)
                {
                    Node *temp1 = seach->previous;
                    Node *temp2 = seach->next;
                    temp1->next = temp2;
                    temp2->previous = temp1;
                }
                else
                {
                    Node *temp3 = seach->previous;
                    temp3->next = NULL;
                    L->last = temp3;
                }
            }
        }
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
    gop(&L);
    xuat(&L);
}