#include <bits/stdc++.h>
using namespace std;
typedef int tuso;
typedef int mauso;
// typedef struct phanso
// {
//     int tuso;
//     int mauso;
// } phanso;
typedef struct Node
{
    tuso ts;
    mauso ms;
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
void nhap(linkedlist *L)
{
    int value;
    cout << "nhap sl  ";
    cin >> value;
    tuso ts1;
    mauso ms1;
    for (int i = 0; i < value; i++)
    {
        cout << "nhap tu so ";
        cin >> ts1;
        cout << "nhap mau so ";
        cin >> ms1;
        Node *newnode = new Node;
        newnode->next = NULL;
        newnode->previous = NULL;
        newnode->ts = ts1;
        newnode->ms = ms1;
        if (L->header->next == NULL)
        {
            L->last->next = newnode;
            newnode->previous = L->last;
            L->last = newnode;
        }
        else
        {
            Node *temp = L->header->next;
            L->header->next = newnode;
            newnode->next = temp;
            temp->previous = newnode;
            newnode->previous = L->header;
        }
    }
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->ts << "/" << cur->ms << "  ";
        cur = cur->next;
    }
}
int ucln(int a, int b)
{
    if (a == 0)
        cout << "k toi gian dc";
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void rutgon(linkedlist *L)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        int ucln1 = ucln(cur->ts, cur->ms);
        if (ucln1 > 1)
        {
            cur->ts /= ucln1;
            cur->ms /= ucln1;
        }
        else if (ucln1 < 0)
        {
            cur->ts /= -ucln1;
            cur->ms /= -ucln1;
        }

        cur = cur->next;
    }
}
void xuat(linkedlist *L)
{
    Node *cur = L->header->next;
    while (cur != NULL)
    {
        cout << cur->ts << "/" << cur->ms << "  ";
        cur = cur->next;
    }
}
int main()
{
    linkedlist L;
    MakeNull(&L);
    nhap(&L);
    rutgon(&L);
    xuat(&L);
}