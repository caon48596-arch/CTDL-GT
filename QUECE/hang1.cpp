#include <bits/stdc++.h>
using namespace std;
#define MAXLEGTH 10
typedef int ElemenType;
typedef struct Queue
{
    ElemenType et[MAXLEGTH];
    int front, rear;
} Queue;
int MakeNull(Queue *Q)
{
    return Q->front = -1;
    Q->front = -1;
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
        cout << "day";
        return;
    }
    else
    {
        if (Empty(Q))
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
            Q->rear = MAXLEGTH - Q->front + 1;
            Q->front = 0;
        }
        Q->rear = Q->rear + 1;
        Q->et[Q->rear] = X;
    }
}
void DEQUEUE(Queue *Q)
{
    if (Empty(Q))
    {
        cout << "day";
    }
    else
    {
        cout << Q->et[Q->front];
        if (Q->front == Q->rear)
        {
            MakeNull(Q);
        }
        else
        {
            Q->front = Q->front + 1;
        }
    }
}
int main()
{
    Queue Q;
    MakeNull(&Q);
    ENQUEUE(&Q, 10);
    ENQUEUE(&Q, 20);
    DEQUEUE(&Q);
    DEQUEUE(&Q);
    ENQUEUE(&Q, 30);
    ENQUEUE(&Q, 40);
    DEQUEUE(&Q);
    DEQUEUE(&Q);
}
