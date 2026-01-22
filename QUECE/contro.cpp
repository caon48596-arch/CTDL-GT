#include <bits/stdc++.h>
using namespace std;
typedef int ElemenType;
typedef struct Node
{
    ElemenType et;
    Node *next;
} Node;
typedef Node *position;
typedef struct Queue
{
    position front;
    position rear;
} Queue;
void init(Queue *Q)
{
    Node *front = (Node *)malloc(sizeof(Node));
    Q->front->next = NULL;
    Q->rear = Q->front;
}
void MakeNull(Queue *Q)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    Q->rear = newnode;
    Q->front = newnode;
}
void ENQUEUE(Queue *Q, ElemenType X)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    newnode->next = NULL;
    Q->rear->next = newnode;
    Q->rear = newnode;
}
void DEQUEUE(Queue *Q)
{
    if (Q->front->next != NULL)
    {
        Q->front = Q->front->next;
        cout << Q->front->et << ' ';
    }
}

int main()
{
    Queue Q;
    MakeNull(&Q);
    init(&Q);
    ENQUEUE(&Q, 10);
    ENQUEUE(&Q, 20);
    DEQUEUE(&Q);
    ENQUEUE(&Q, 30);
    ENQUEUE(&Q, 40);
    DEQUEUE(&Q);
}