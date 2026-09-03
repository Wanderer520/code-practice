//
// Created by hp on 2026/8/18.
//
#include<stdio.h>      // 标准输入输出头文件，用于 printf / scanf

// 注意：在 C 语言中使用 bool 类型需要引入 <stdbool.h> 头文件

#define MAXSIZE 100    // 顺序表的最大容量（最多能存储 100 个元素）
typedef int ElemType;  // 将 int 类型重命名为 ElemType，便于以后修改元素类型

/**
 * 顺序表结构体定义
 * data   : 用定长数组存储元素
 * length : 当前顺序表中实际存储的元素个数（有效长度）
 */
typedef struct
{
    ElemType data[MAXSIZE];  // 存储元素的数组，下标范围：0 ~ MAXSIZE-1
    int length;              // 当前顺序表的长度（元素个数）
} SqList;

/**
 * 在顺序表中查找元素 e
 * @param L 顺序表（按值传递，不会修改原表）
 * @param e 要查找的目标元素
 * @return 元素 e 在表中的下标（从 0 开始）；若未找到，返回 -1
 */
int Find(SqList L, ElemType e)
{
    // 遍历整个顺序表，逐一比较元素
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)   // 找到与 e 相等的元素
            return i;         // 返回其下标
    return -1;                // 遍历完都没找到，返回 -1 表示查找失败
}

/**
 * 在顺序表第 i 个位置插入元素 e
 * @param L 指向顺序表的指针（按引用传递，可以修改原表）
 * @param i 插入位置，取值范围：1 ~ length+1
 *          （第 1 个位置为表首，第 length+1 个位置为表尾）
 * @param e 要插入的元素
 * @return 插入成功返回 true；插入失败返回 false
 */
bool Insert(SqList* L, int i, ElemType e)
{
    // 1. 判断表是否已满：若长度达到最大容量，则无法插入
    if (L->length >= MAXSIZE)
        return false;

    // 2. 判断插入位置是否合法：i 必须在 [1, length+1] 范围内
    if (i < 1 || i > L->length+1)
        return false;

    // 3. 从最后一个元素开始，将下标 j 的元素依次后移一位，
    //    为插入元素腾出位置（腾出下标为 i-1 的位置）
    for (int j = L->length - 1; j >= i - 1; j--)
        L->data[j + 1] = L->data[j];

    // 4. 将新元素 e 放到下标 i-1 的位置上
    L->data[i - 1] = e;

    // 5. 表长加 1
    L->length++;

    return true;  // 插入成功
}

/**
 * 删除顺序表中第 i 个位置的元素，并通过 e 带回被删除的元素
 * @param L 指向顺序表的指针（按引用传递，可以修改原表）
 * @param i 删除位置，取值范围：1 ~ length
 * @param e 指针，用于接收被删除的元素值
 * @return 删除成功返回 true；删除失败返回 false
 */
bool Delete(SqList* L, int i, ElemType* e)
{
    // 1. 判断删除位置是否合法：i 必须在 [1, length] 范围内
    if (i < 1 || i > L->length)
        return false;

    // 2. 先将待删除的元素保存到 *e 中（通过指针带回给调用者）
    *e = L->data[i - 1];

    // 3. 将下标 i-1 之后的元素依次前移一位，覆盖被删除元素的位置
    for (int j = i - 1; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];

    // 4. 表长减 1
    L->length--;

    return true;  // 删除成功
}

/**
 * 主函数：程序入口
 * 功能：先输入顺序表的长度，再输入各个元素，并存入顺序表
 */
int main()
{
    SqList L;  // 定义一个顺序表变量

    // 输入顺序表的长度（即元素个数）
    scanf("%d", &L.length);

    // 循环输入 length 个元素，依次存入数组
    for (int i = 0; i < L.length; i++)
        scanf("%d", &L.data[i]);

}