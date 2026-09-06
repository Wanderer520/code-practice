//
// Created by hp on 2026/9/5.
//
#include <stdio.h>
#include<stdlib.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode;

BSTNode* pre = NULL;
bool flag = true; //true表示为二叉搜索树，flase表示不是二叉搜索树

BSTNode* FindMin(BSTNode* p)
{
    while (p->lchild)
        p = p->lchild;
    return p;
}

//递归版
void InOrder(BSTNode* root)
{
    if (root)
    {
        InOrder(root->lchild);
        printf("%d ", root->data);
        InOrder(root->rchild);
    }
}

BSTNode* SearchRec(BSTNode* root, int x)
{
    if (root == NULL)
        return NULL;
    else if (x < root->data)
        return SearchRec(root->lchild, x);
    else if (x > root->data)
        return SearchRec(root->rchild, x);
    else
        return root;
}

void InsertRec(BSTNode** root, int x)
{
    if (*root == NULL)
    {
        *root = (BSTNode*)malloc(sizeof(BSTNode));
        (*root)->data = x;
        (*root)->lchild = (*root)->rchild = NULL;
    }
    else if (x < (*root)->data)
        return InsertRec(&(*root)->lchild, x);
    else if (x > (*root)->data)
        return InsertRec(&(*root)->rchild, x);
}

void DeleteRec(BSTNode** root, int x)
{
    if (*root == NULL)
        return;
    else if (x < (*root)->data)
        return DeleteRec(&(*root)->lchild, x);
    else if (x > (*root)->data)
        return DeleteRec(&(*root)->rchild, x);
    else
    {
        if ((*root)->lchild == NULL && (*root)->rchild == NULL)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->lchild && (*root)->rchild == NULL)
        {
            BSTNode* temp = *root;
            *root = (*root)->lchild;
            free(temp);
        }
        else if ((*root)->lchild == NULL && (*root)->rchild)
        {
            BSTNode* temp = *root;
            *root = (*root)->rchild;
            free(temp);
        }
        else
        {
            BSTNode* next = FindMin((*root)->rchild);
            (*root)->data = next->data;
            DeleteRec(&(*root)->rchild, next->data);
        }
    }
}

//非递归版
BSTNode* SearchIter(BSTNode* root, int x)
{
    while (root)
    {
        if (x < root->data)
            root = root->lchild;
        else if (x > root->data)
            root = root->rchild;
        else
            break;
    }
    return root;
}

BSTNode* Create(int val[], int length)
{
    BSTNode* root = NULL;
    for (int i = 0; i < length; i++)
    {
        InsertRec(&root, val[i]);
    }
    return root;
}

void JudgeBST(BSTNode* root)
{
    if (root && flag)
    {
        JudgeBST(root->lchild);
        if (pre == NULL)
            pre = root;
        else if (pre->data >= root->data)
        {
            flag = false;
            pre = root;
        }
        else
        {
            flag = true;
            pre = root;
        }
        JudgeBST(root->rchild);
    }
}

int main(void) {
    int a[] = {50, 30, 80, 20, 40, 90, 35};
    BSTNode* root = Create(a, 7);
    InOrder(root); printf("\n");                       // 期望：20 30 35 40 50 80 90

    printf("%s\n", SearchRec(root, 40)  ? "40 found" : "40 missing");    // found
    printf("%s\n", SearchIter(root, 55) ? "55 found" : "55 missing");    // missing

    DeleteRec(&root, 50);              // 删根：两孩子（80 顶替）
    DeleteRec(&root, 20);              // 删叶子
    DeleteRec(&root, 40);              // 删只有一个左孩子(35)的节点
    InOrder(root); printf("\n");                       // 期望：30 35 80 90

    pre = NULL; flag = 1;                              // 判断前必须重置全局状态
    JudgeBST(root);
    printf("%s\n", flag ? "is BST" : "not BST");       // 期望：is BST

    root->lchild->rchild->data = 100;  // 故意破坏（35 -> 100），应能判出 not BST
    pre = NULL; flag = 1;
    JudgeBST(root);
    printf("%s\n", flag ? "is BST" : "not BST");       // 期望：not BST
    return 0;
}
