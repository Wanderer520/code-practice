//
// Created by hp on 2026/8/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct SNode
{
    int data;
    struct SNode* next;
} SNode, *LinkStack;

bool Push(LinkStack* s, int e)
{
    SNode* x = (SNode*)malloc(sizeof(SNode));
    x->data = e;
    x->next = *s;
    *s = x;
    return true;
}

bool Pop(LinkStack* s, int* e)
{
    if (*s == NULL)
        return false;
    SNode* p = *s;
    *s= p->next;
    *e = p->data;
    free(p);
    return true;
}

int main()
{
    LinkStack s = (LinkStack)malloc(sizeof(SNode));
    printf("Enter the number of elements to push onto the stack: \n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        Push(&s, e);
    }
    while (1)
    {
        printf("Enter 1 to pop an element, 0 to exit: \n");
        int choice;
        scanf("%d", &choice);
        if (choice == 0)
            break;
        if (choice == 1)
        {
            int e;
            if (Pop(&s, &e))
                printf("Popped element: %d\n", e);
            else
                printf("Stack is empty\n");
        }
    }
    return 0;
}
