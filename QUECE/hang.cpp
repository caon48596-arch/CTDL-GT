#include <bits/stdc++.h>
using namespace std;
#define MAXLEGTH 4
typedef int elemenType;
typedef struct Queue
{
    elemenType et[MAXLEGTH];
    int front, rear;
} Queue;
void makenull(Queue *Q)
{
    Q->front = -1;
    Q->rear = -1;
}
int empty(Queue *Q)
{
    return Q->front == -1;
}
int full(Queue *Q)
{
    return (Q->rear - Q->front + 1) % MAXLEGTH == 0;
}
void ENQUEUE(Queue *Q, elemenType X)
{
    if (full(Q))
    {
        cout << " day ";
        return;
    }
    else
    {
        if (empty(Q))
        {
            Q->front = 0;
            Q->rear = -1;
        }
        else if (Q->rear == MAXLEGTH - 1)
        {
            for (int i = Q->front; i < Q->rear; i++)
            {
                Q->et[i - Q->front] = Q->et[i];
            }
            Q->rear = MAXLEGTH - Q->front - 1;
            Q->front = 0;
        }
        Q->rear = Q->rear + 1;
        Q->et[Q->rear] = X;
    }
}

void DEQUEUE(Queue *Q)
{
    if (empty(Q))
    {
        cout << " k co gia tri de in";
    }
    else
    {
        cout << Q->et[Q->front];
        if (Q->front == Q->rear)
        {
            makenull(Q);
        }
        else
        {
            Q->front = (Q->front + 1) % MAXLEGTH;
        }
    }
}
int main()
{
    Queue Q;
    makenull(&Q);
    ENQUEUE(&Q, 10);
    ENQUEUE(&Q, 20);
    DEQUEUE(&Q);
    DEQUEUE(&Q);
    ENQUEUE(&Q, 30);
    ENQUEUE(&Q, 40);
    DEQUEUE(&Q);
    DEQUEUE(&Q);
}