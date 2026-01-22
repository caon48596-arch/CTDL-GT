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
void Init(Queue *Q)
{
    Node *front = (Node *)malloc(sizeof(Node));
    Q->front->next = NULL;
    Q->rear = Q->front;
}
void MakeNull(Queue *Q)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->next = NULL;
    Q->front = newnode;
    Q->rear = newnode;
}
void Empty(Queue *Q)
{
    Q->front == Q->rear;
}
void ENQUEUE(ElemenType X, Queue *Q)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->et = X;
    newnode->next = NULL;
    Q->rear->next = newnode;
    Q->rear = newnode;
}
void DEQUEUE(Queue *Q)
{
    if (Q->front != Q->rear)
    {
        Q->front = Q->front->next;
    }
    cout << Q->front->et;
}
int main()
{
    Queue Q;
    MakeNull(&Q);
    ENQUEUE(10, &Q);
    DEQUEUE(&Q);
}