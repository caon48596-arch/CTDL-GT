#include <bits\stdc++.h>
using namespace std;
#define MAXLEGTH 4
typedef int ElemenType;
typedef struct Queue
{
    ElemenType et[MAXLEGTH];
    int front, rear;
} Queue;
int MakeNull(Queue *Q)
{
    return Q->front = -1, Q->front = -1;
}
int empty(Queue *Q)
{
    return Q->front == -1;
}
int FullQueue(Queue *Q)
{
    return (Q->rear - Q->front + 1) % MAXLEGTH == 0;
}
void ENQUEUE(Queue *Q, ElemenType X)
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
void DEQUECE(Queue *Q, int value)
{
    for (int i = 0; i < value; i++)
    {
        if (empty(Q))
        {
            cout << "rong";
        }

        cout << Q->et[Q->front] << ' ';
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
    ENQUEUE(&Q, 10);
    ENQUEUE(&Q, 20);
    ENQUEUE(&Q, 30);
    DEQUECE(&Q, 2);
    ENQUEUE(&Q, 40);
    DEQUECE(&Q, 2);
}