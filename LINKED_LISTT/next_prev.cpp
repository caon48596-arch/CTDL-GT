#include <bits\stdc++.h>
#include <bits\stdc++.h>
using namespace std;
typedef int elemenType;
typedef struct Node
{
    elemenType et;
    Node *next;
} Node;
typedef Node *position;
typedef struct linkedlist
{
    position header;
    position last;
} linkedlist;
void init(linkedlist *L)
{
    Node *header = (Node *)malloc(sizeof(Node));
    L->header->next = NULL;
    L->last = L->header;
}
void nhap(linkedlist *L, elemenType X)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    newnode->next = NULL;
    L->last->next = newnode;
    L->last = newnode;
}
void xuat(linkedlist *L, elemenType X)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->et << ' ';
        cur = cur->next;
    }
}
void next(linkedlist *L, int index, int value)
{
    position nextt = L->header->next;
    for (int i = 1; i < value && nextt != NULL; nextt = nextt->next, i++)
    {
        if (i == index)
        {
            cout << nextt->next->et << "vi tri " << i + 1;
            return;
        }
        else if (index >= value)
        {
            cout << "sai";
            return;
        }
    }
}

void prev(linkedlist *L, int index, int value)
{
    position prev = L->header->next;
    position prev2 = L->header;
    for (int i = 1; i <= value && prev != NULL; prev = prev->next, prev2 = prev2->next, i++)
    {
        if (i == index && index > 2)
        {
            cout << prev2->et << "vi tri " << i - 1;
            return;
        }
        else if (index < 2 || index > value)
        {
            cout << "sai";
            return;
        }
    }
}
int main()
{
    linkedlist L;
    init(&L);
    cout
        << "nhap sl ";
    int value;
    cin >> value;
    elemenType A;
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    xuat(&L, A);
    int index;
    cin >> index;
    // next(&L, index, value);
    prev(&L, index, value);
}