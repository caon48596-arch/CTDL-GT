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
void MAKENULL(linkedlist *L)
{
    L->header = 0;
}
void init(linkedlist *L)
{
    // L = (linkedlist *)malloc(sizeof(linkedlist));
    L->header = (Node *)malloc(sizeof(Node));
    if(L->last == NULL){
        cout << "khong co gia tri ";
        exit(1);
    }
    L->header->next = NULL;
    L->last = L->header;
}
void nhap(linkedlist *L, elemenType value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(L->last == NULL){
        cout << "k co gia tri";
        exit(1);
    }
    newnode->et = value;
    newnode->next = NULL;
    L->last->next = newnode;
    L->last = newnode;
}
void DELETE(linkedlist *L, int index)
{
    position prev = L->header;
    for (int i = 0; i < index - 1 && prev != NULL; i++)
    {
        prev = prev->next;
    }
    position temp = prev->next;
    prev->next = temp->next;
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
int main()
{
    linkedlist L;
    MAKENULL(&L);
    cout << "nhap sl ";
    int value;
    cin >> value;
    init(&L);
    elemenType A;
    cout << "cac so la ";
    for (int i = 0; i < value; i++)
    {
        cin >> A;
        nhap(&L, A);
    }
    int index;
    cin >> index;
    DELETE(&L, index);
    elemenType X;
    xuat(&L, X);
}