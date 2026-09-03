//
// Created by hp on 2026/8/25.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

bool isEmpty(SqQueue* q)
{
    return q->front == q->rear;
}

bool isFull(SqQueue* q)
{
    return (q->rear + 1) % MAXSIZE == q->front;
}

bool EnQueue(SqQueue* q, int e)
{
    if (isFull(q))
        return false;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue* q, int* e)
{
    if (isEmpty(q))
        return false;
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return true;
}

int Length(SqQueue* q)
{
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

int main()
{
    SqQueue* q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = 0;
    q->rear = 0;
    while (1)
    {
        int choice;
        printf("1. EnQueue\n2. DeQueue\n3. Length\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // EnQueue
            int x;
            printf("Enter an integer to enqueue: ");
            scanf("%d", &x);
            EnQueue(q, x);
            break;
        case 2:
            // DeQueue
            int* e = (int*)malloc(sizeof(int));
            if (DeQueue(q, e))
                printf("Dequeued element: %d\n", *e);
            else
                printf("Queue is empty\n");
            free(e);
            break;
        case 3:
            // Length
            printf("Length of queue: %d\n", Length(q));
            break;
        case 4:
            // Exit
            exit(0);
        }
    }
}
