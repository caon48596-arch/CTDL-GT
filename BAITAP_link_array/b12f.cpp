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
typedef struct check1
{
    Node *p1;
    Node *p2;
} check1;
void nhap(linkedlist *L)
{
    int value;
    cin >> value;
    phanso ps;
    for (int i = 0; i < value; i++)
    {
        cout << "nhap ts ";
        cin >> ps.tuso;
        cout << "nhap ms ";
        cin >> ps.mauso;
        Node *newnode = new Node;
        newnode->ps = ps;
        newnode->next = NULL;
        newnode->previous = NULL;
        L->last->next = newnode;
        newnode->previous = L->last;
        L->last = newnode;
    }
}

int check(linkedlist *L, Node *&contro1, Node *&contro2)
{
    contro1 = NULL;
    contro2 = NULL;
    Node *limit = L->last;
    for (Node *i = L->header->next; i != limit->next; i = i->next)
    {
        for (Node *j = i->next; j != limit->next; j = j->next)
        {
            int tichtuso = i->ps.tuso * j->ps.tuso;
            int tichmauso = i->ps.mauso * j->ps.mauso;
            if (tichtuso == tichmauso)
            {
                contro1 = i;
                contro2 = j;
                return 1;
            }
        }
    }
}
void xuat(linkedlist *L)
{
    Node *cur = L->header->next;
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
    xuat(&L);
    Node *p1;
    Node *p2;
    int ketqua = check(&L, p1, p2);
    if (ketqua == NULL)
    {
        cout << "Ket qua: (NULL, NULL) - Khong tim thay." << endl;
    }
    else
    {
        cout << "Tim thay cap tai dia chi " << p1 << " va " << p2 << endl;
        cout  << p1->ps.tuso << "/" << p1->ps.mauso << ") va (" << p2->ps.tuso << "/" << p2->ps.mauso << ")" << endl;
    }
}
