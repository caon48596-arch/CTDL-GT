#include <bits/stdc++.h>
using namespace std;
#define MAX 10
typedef int ElemenType;
typedef struct Node
{
    ElemenType ET;
    Node *Next;
    Node *previous;
} Node;
typedef Node *position;
typedef struct Linkedlist
{
    position header;
    position last;
} Linkedlist;
typedef Linkedlist Dictionary[MAX];

void MakeNull(Dictionary &D)
{
    for (int i = 0; i < MAX; i++)
    {
        D[i].header = new Node;
        D[i].header->Next = NULL;
        D[i].header->previous = NULL;
        D[i].last = D[i].header;
    }
}
int h(ElemenType X)
{
    return abs(X) % 10;
}
int Member(ElemenType X, Dictionary &D)
{
    Node *P = D[h(X)].header->Next;
    while (P != NULL)
    {
        if (P->ET == X)
        {
            return 1;
        }
        else
        {
            P = P->Next;
        }
    }
    return 0;
}
void Insert(ElemenType X, Dictionary &D)
{
    int Bucket;
    if (!Member(X, D))
    {
        Bucket = h(X);
        Node *newnode = new Node;
        newnode->Next = NULL;
        newnode->previous = NULL;
        newnode->ET = X;
        D[Bucket].last->Next = newnode;
        newnode->previous = D[Bucket].last;
        D[Bucket].last = newnode;
    }
}
void Delete(ElemenType X, Dictionary &D)
{
    int Bucket;
    if (Member(X, D))
    {
        Bucket = h(X);
        Node *seach = D[Bucket].header->Next;
        while (seach != NULL)
        {
            if (seach->ET == X)
            {
                if (D[Bucket].header->Next == D[Bucket].last)
                {
                    D[Bucket].header->Next = NULL;
                    D[Bucket].last = D[Bucket].header;
                }
                else if (seach == D[Bucket].last)
                {
                    seach->previous->Next = NULL;
                    D[Bucket].last = seach;
                }
                else if (seach->Next != NULL)
                {
                    Node *temp = seach->Next;
                    seach->previous->Next = temp;
                    temp->previous = seach;
                }
                delete seach;
                return;
            }
            seach = seach->Next;
        }
    }
}
void PrintDictionary(Dictionary &D)
{
    for (int i = 0; i < MAX; i++)
    {
        cout << "Bucket " << i << ": ";
        Node *P = D[i].header->Next;
        while (P != NULL)
        {
            cout << P->ET << " -> ";
            P = P->Next;
        }
        cout << "NULL" << endl;
    }
}
int main()
{
    Dictionary D;
    MakeNull(D);
    cout << "Nhap sl ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap so ";
        ElemenType A;
        cin >> A;
        Insert(A, D);
    }
    PrintDictionary(D);
    cout << "nhap so can tim ";
    ElemenType X;
    cin >> X;
    cout << "da tim thay " << X << endl;
    Delete(X, D);
    PrintDictionary(D);
}
