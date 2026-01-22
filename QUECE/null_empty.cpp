#include <bits\stdc++.h>
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
    return Q->front, Q->front = -1;
}
int empty(Queue *Q)
{
    return Q->front == -1;
}
int FullQueue(Queue *Q)
{
    return (Q->rear - Q->front + 1) % MAXLEGTH == 0;
}
void ENQUEUE(ElemenType X, Queue *Q)
{
    if (FullQueue(Q))
    {
        cout << "hang day";
    }
    else
    {
        if (empty(Q))
        {
            Q->front = 0, Q->rear = 0;
        }
        else
        {
            Q->rear = (Q->rear + 1) % MAXLEGTH;
        }
        Q->et[Q->rear] = X;
    }
}
void DEQUECE(Queue *Q)
{
    if (empty(Q))
    {
        cout << "rong";
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
            Q->front = (Q->front + 1) % MAXLEGTH;
        }
    }
}
int main()
{
    Queue Q;
    MakeNull(&Q);
    ENQUEUE(3, &Q);
    ENQUEUE(4, &Q);
    DEQUECE(&Q);
    DEQUECE(&Q);
    ENQUEUE(5, &Q);
    DEQUECE(&Q);
}