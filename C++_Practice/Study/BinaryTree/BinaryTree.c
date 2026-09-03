//
// Created by hp on 2026/8/30.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct BTNode
{
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode, *BTree;

//建树
void Init(BTree* T)
{
    *T = NULL;
}

void creat(BTree* T, int val)
{
    if (val == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BTree)malloc(sizeof(BTNode));
        (*T)->data = val;
        int lval, rval;
        printf("Please enter the left child of %d(enter # to finish): ", val);
        scanf(" %d", &lval);
        creat(&((*T)->lchild), lval);
        printf("Please enter the right child of %d(enter # to finish): ", val);
        scanf(" %d", &rval);
        creat(&((*T)->rchild), rval);
    }
}

void visit(BTree p)
{
    printf("%d ", p->data);
}

//递归遍历
void PreOrder(BTree T)
{
    if (T == NULL) return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

void InOrder(BTree T)
{
    if (T == NULL) return;
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
}

void PostOrder(BTree T)
{
    if (T == NULL) return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}

//非递归遍历
typedef struct
{
    BTree data[MAXSIZE];
    int top;
} SqStack;

typedef struct
{
    BTree data[MAXSIZE];
    int front, rear; //rear指向队尾下一个
} SqQueue;

void InitStack(SqStack* S)
{
    S->top = -1;
}

bool StackEmpty(SqStack* S)
{
    return S->top == -1;
}

void Push(SqStack* S, BTree p)
{
    S->data[++S->top] = p;
}

BTree Pop(SqStack* S)
{
    return S->data[S->top--];
}

void InitQueue(SqQueue* Q)
{
    Q->front = Q->rear = 0;
}

bool QueueEmpty(SqQueue* Q)
{
    return Q->rear == Q->front;
}

bool QueueFull(SqQueue* Q)
{
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

void EnQueue(SqQueue* Q, BTree p)
{
    Q->data[Q->rear++] = p;
}

BTree DeQueue(SqQueue* Q)
{
    return Q->data[Q->front++];
}

void PreOrder2(BTree T)
{
    SqStack S;
    InitStack(&S);
    BTree p = T;
    while (p || !StackEmpty(&S))
    {
        if (p)
        {
            visit(p);
            Push(&S, p);
            p = p->lchild;
        }
        else
        {
            p = Pop(&S);
            p = p->rchild;
        }
    }
}

void InOrder2(BTree T)
{
    SqStack S;
    InitStack(&S);
    BTree p = T;
    while (p || !StackEmpty(&S))
    {
        if (p)
        {
            Push(&S, p);
            p = p->lchild;
        }
        else
        {
            p = Pop(&S);
            visit(p);
            p = p->rchild;
        }
    }
}

void PostOrder2(BTree T)
{
    SqStack S1, S2;
    InitStack(&S1);
    InitStack(&S2);
    BTree p = T;
    while (p || !StackEmpty(&S1))
    {
        if (p)
        {
            Push(&S2, p);
            Push(&S1, p);
            p = p->rchild;
        }
        else
        {
            p = Pop(&S1);
            p = p->lchild;
        }
    }
    while (!StackEmpty(&S2)) visit(Pop(&S2));
}

void LevelOrder(BTree T)
{
    SqQueue Q;
    InitQueue(&Q);
    if (T) EnQueue(&Q, T);
    while (!QueueEmpty(&Q))
    {
        BTree p = DeQueue(&Q);
        visit(p);
        if (p->lchild) EnQueue(&Q, p->lchild);
        if (p->rchild) EnQueue(&Q, p->rchild);
    }
}

BTree build(int pre[], int pl, int pr, int in[], int il, int ir)
{
    if (pl > pr) return NULL;
    BTree root = (BTree)malloc(sizeof(BTNode));
    root->data = pre[pl];
    int k = il;
    while (k <= ir && in[k] != pre[pl]) k++;
    int leftLen = k - il;
    root->lchild = build(pre, pl + 1, pl + leftLen, in, il, k - 1);
    root->rchild = build(pre, pl + leftLen + 1, pr, in, k + 1, ir);
    return root;
}

int main()
{
    BTree T;
    Init(&T);
    int choose;
    printf("Please choose an option:\n");
    printf("1. Create tree by inputting values\n");
    printf("2. Build tree from PreOrder and InOrder traversals\n");
    scanf("%d", &choose);
    if (choose==1)
    {
        printf("Please enter the node's value(enter -1 to finish): ");
        int val;
        scanf("%d", &val);
        creat(&T, val);
        printf("PreOrder: ");
        PreOrder(T);
        printf("\nInOrder: ");
        InOrder(T);
        printf("\nPostOrder: ");
        PostOrder(T);
        printf("\n");
    }
    else if (choose == 2)
    {
        int n;
        printf("Please enter the number of nodes: ");
        scanf("%d", &n);
        printf("Please enter PreOrder and InOrder traversals :\n");
        int Pre[n], In[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &Pre[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &In[i]);
        T = build(Pre, 0, n - 1, In, 0, n - 1);
        printf("PostOrder: ");
        PostOrder(T);
        printf("\nLevelOrder: ");
        LevelOrder(T);
        printf("\n");
    }
    return 0;
}
