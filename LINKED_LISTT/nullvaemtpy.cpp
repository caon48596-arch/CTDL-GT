#include <bits/stdc++.h>
using namespace std;

typedef int elemenType;
typedef struct Node
{
    elemenType ET;
    Node *next;
};
typedef Node *Posotion;
// typedef Posotion List;
typedef struct linkedlist
{
    Posotion header;
    Posotion last;
};

void init_list(linkedlist &L)
{
    // Tạo nút header
    L.header = (Node *)malloc(sizeof(Node));
    L.header->next = NULL;
    L.last = L.header;
}
void makenode(linkedlist &L, elemenType value)
{
    Posotion newNode = (Node *)malloc(sizeof(Node));
    newNode->ET = value;
    newNode->next = NULL;
    L.last->next = newNode;
    L.last = newNode;
}
void printList(linkedlist &L) // Không cần truyền tham chiếu & vì không thay đổi Header
{
    Node *cur = L.header->next;
    if (cur == NULL)
    {
        cout << "Danh sach rong.";
    }
    while (cur != NULL)
    {
        cout << cur->ET << " "; // Thêm dấu cách
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    linkedlist L;
    init_list(L);
    cout << "Danh sach lien ket: ";
    elemenType A;
    cin >> A;
    makenode(L, A);
    printList(L);

    return 0;
}