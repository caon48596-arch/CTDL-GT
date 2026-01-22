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
typedef struct Linkedlist
{
    position header;
    position last;
} Linkedlist;
void MakeNull(Linkedlist *L)
{
    L->header = (Node *)malloc(sizeof(Node));
    L->header->next = NULL;
    L->header->previous = NULL;
    L->last = L->header;
}
int Empty(Linkedlist *L)
{
    return L->header == NULL;
}
void nhap(Linkedlist *L, ElemenType X)
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
void xuat(Linkedlist *L)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << " ";
        cur = cur->next;
    }
}
void seach(Linkedlist *L)
{
    int value;
    cout << "nhap gia tri can tim";
    cin >> value;
    Node *seach = L->header->next;
    int i;
    int deletee = i;
    for (i = 0; seach != NULL; i++)
    {
        if (seach->et != value)
        {
            seach = seach->next;
        }
        else
        {
            cout << seach->et << "vi tri " << i + 1;
            break;
        }
    }
    Node *temp1 = seach->previous;
    Node *temp2 = seach->next;
    temp1->next = temp2;
    temp2->previous = temp1;
}

int main()
{
    Linkedlist L;
    MakeNull(&L);
    ElemenType A;
    int value;
    cin >> value;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    xuat(&L);
    seach(&L);
    xuat(&L);
}