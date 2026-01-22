#include <bits/stdc++.h>
using namespace std;
#define MAXLEGTH 10
typedef int ElemenType;
typedef struct Queue
{
    ElemenType et[MAXLEGTH];
    int front, rear;
} Queue;
int MakeNUll(Queue *Q)
{
    return Q->front = -1;
    Q->rear = -1;
}
int Empty(Queue *Q)
{
    return Q->front == -1;
}
int Full(Queue *Q)
{
    return (Q->rear - Q->front + 1) % MAXLEGTH == 0;
}
void ENQUEUE(Queue *Q, ElemenType X)
{
    if (Full(Q))
    {
        cout << "day ";
    }
    else
    {
        if (Empty(Q))
        {
            Q->front = 0;
            Q->rear = 0;
        }
        else if (Q->rear == MAXLEGTH - 1)
        {
            Q->rear = Q->rear + 1 - MAXLEGTH;
        }
        Q->et[Q->rear] = X;
        Q->rear++;
    }
}
void DEQUEUE(Queue *Q)
{
    if (Empty(Q))
    {
        cout << "khong trong ";
    }
    else
    {
        cout << Q->et[Q->front];
        if (Q->front == Q->rear)
        {
            MakeNUll(Q);
        }
        else
        {
            Q->front = Q->front + 1 % MAXLEGTH;
        }
    }
}
int main()
{
    Queue Q;
    MakeNUll(&Q);
    ENQUEUE(&Q, 10);
    ENQUEUE(&Q, 20);
    DEQUEUE(&Q);
    DEQUEUE(&Q);
    ENQUEUE(&Q, 30);
    ENQUEUE(&Q, 40);
    DEQUEUE(&Q);
    DEQUEUE(&Q);
}