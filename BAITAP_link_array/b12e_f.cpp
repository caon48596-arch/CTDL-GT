#include <bits/stdc++.h>
using namespace std;
typedef struct phanso
{
    int tuso;
    int mauso;
} phanso;
typedef struct Node
{
    phanso ps;
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
int nhap(linkedlist *L)
{
    int value;
    cin >> value;
    phanso temp;
    for (int i = 0; i < value; i++)
    {
        cout << "nhap ts ";
        cin >> temp.tuso;
        cout << "nhap ms ";
        cin >> temp.mauso;
        Node *newnode = new Node;
        newnode->next = NULL;
        newnode->previous = NULL;
        newnode->ps = temp;
        L->last->next = newnode;
        newnode->previous = L->last;
        L->last = newnode;
    }
}

void xoa_phan_tu(linkedlist *L)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        Node *temp = cur->next;
        if (cur->ps.tuso > cur->ps.mauso)
        {
            cur->previous->next = cur->next;
            if (cur->next != NULL)
            {
                cur->next->previous = cur->previous;
            }
            else
            {
                L->last = cur->previous;
            }
            delete cur;
        }
        cur = temp;
    }
}
void xuat(linkedlist *L)
{
    Node *cur = L->header->next;
    if (cur == NULL)
    {
        cout << "k co gia tri";
    }
    while (cur != NULL)
    {
        cout << cur->ps.tuso << "/" << cur->ps.mauso << " ";
        cur = cur->next;
    }
}
int main()
{
    linkedlist L;
    MakeNull(&L);
    nhap(&L);
    xoa_phan_tu(&L);
    xuat(&L);
}