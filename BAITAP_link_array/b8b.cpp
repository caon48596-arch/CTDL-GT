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
;
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
void empty(linkedlist *L)
{
    L->last == NULL;
}
int check(linkedlist *L, ElemenType S)
{
    Node *cur = L->last;
    while (S == cur->et)
    {
        return 1;
    }
    cur = cur->previous;
}
void nhap(linkedlist *L)
{
    int n;
    cin >> n;
    ElemenType S;
    for (int i = 0; i < n; i++)
    {
        cin >> S;
        while (check(L, S) == 1)
        {
            cout << "yeu cau nhap lai";
            cin >> S;
        }
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->next = NULL;
        newnode->previous = NULL;
        newnode->et = S;
        if (L->header->next == NULL)
        {
            L->last->next = newnode;
            newnode->previous = L->last;
            L->last = newnode;
        }
        else
        {
            if (newnode->et < L->last->et)
            {
                L->last->next = newnode;
                newnode->previous = L->last;
                L->last = newnode;
            }
            else
            {
                Node *temp = L->last;
                while (newnode->et > temp->et && temp != L->header)
                {
                    temp = temp->previous;
                }

                Node *temp1 = temp->next;
                temp->next = newnode;
                newnode->next = temp1;
                temp1->previous = newnode;
                newnode->previous = temp;
            }
        }
    }
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
int main()
{
    linkedlist L;
    MakeNull(&L);
    nhap(&L);
    xuat(&L);
}