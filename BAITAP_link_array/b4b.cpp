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
void Empty(linkedlist *L)
{
    L->last == NULL;
}
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
void chen(linkedlist *L, int value, ElemenType X)
{
    if (value < 1)
    {
        cout << "gia tri sai";
        exit(1);
    }
    Node *temp = L->header;
    for (int i = 0; i < value && temp != NULL; i++)
    {
        temp = temp->next;
    }
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    newnode->next = NULL;
    newnode->previous = NULL;
    Node *temp1 = temp->previous;
    temp1->next = newnode;
    newnode->next = temp;
    temp->previous = newnode;
    newnode->previous = temp1;
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
    cout << "\n";
    int vitri;
    cin >> vitri;
    int giatri;
    cin >> giatri;
    chen(&L, vitri, giatri);
    xuat(&L);
}