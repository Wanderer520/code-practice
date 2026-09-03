//
// Created by hp on 2026/8/25.
//
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

bool isEmpty(SqStack* s)
{
    return s->top == -1;
}

bool isFull(SqStack* s)
{
    return s->top == MAXSIZE - 1;
}

bool Push(SqStack* s, ElemType e)
{
    if (isFull(s)) return false;
    s->data[++s->top] = e;
    return true;
}

bool Pop(SqStack* s, ElemType* e)
{
    if (isEmpty(s)) return false;
    *e = s->data[s->top--];
    return true;
}

int main()
{
    SqStack* s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
    printf("Enter the number of elements to push onto the stack: \n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ElemType e;
        scanf("%d", &e);
        Push(s, e);
    }
    printf("1.Push 2.Pop 3.Exit\n");
    while (1)
    {
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to push: \n");
                ElemType p;
                scanf("%d", &p);
                Push(s, p);
                break;
            case 2:
                ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                Pop(s, e);
                printf("Popped element: %d\n", *e);
                free(e);
                break;
            case 3:
                exit(0);
        }
    }
}
