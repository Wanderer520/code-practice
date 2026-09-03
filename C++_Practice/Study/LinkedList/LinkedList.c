//
// Created by hp on 2026/8/19.
//
#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode;

void Print(LNode* L)
{
    int count = 0;
    LNode* p = L->next;
    while (p != NULL)
    {
        count++;
        printf("%d ", p->data);
        p = p->next;
    }
    printf("The length of the linked list is: %d\n", count);
}

LNode* FindKth(LNode* L, int k)
{
    if (k < 0)
        return NULL;
    int i = 0;
    LNode* p = L;
    while (p != NULL && i < k)
    {
        p = p->next;
        i++;
    }
    return p;
}

LNode* Find(LNode* L, ElemType e)
{
    LNode* p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

bool Insert(LNode* L, int i, ElemType e)
{
    LNode* p = FindKth(L, i - 1);
    if (p == NULL)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool Delete(LNode* L, int i, ElemType* e)
{
    LNode* p = FindKth(L, i - 1);
    if (p == NULL)
        return false;
    LNode* q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

int main()
{
    printf("The path of the editor I'm using is:%s\n", __FILE__);
    LNode* L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* tail = L;
    int length;
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &s->data);
        //尾插法
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
    Print(L);
    return 0;
}
