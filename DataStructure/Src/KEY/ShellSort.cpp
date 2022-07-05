/*

        CopyRight By Aphcity
        2021年11月06日

*/

#include <stdio.h>

#define MaxSize 10

typedef struct SqList
{
    int data[MaxSize];
    int length;
} SqList;

bool InitList(SqList &L);
/**
 * 哨兵顺序表插入
 * @param L
 * @param Pos 插入下标
 * @param t 插入元素
 */
bool InsertList(SqList &L, int pos, int t);
bool DeleteList(SqList &L, int &t);
int LocateElem(SqList &L, int t);
bool PrintList(SqList L);

bool InitList(SqList &L)
{
    L.data[0] = -1;
    L.length = 0;
    return true;
}

bool InsertList(SqList &L, int pos, int t)
{
    if (L.length == MaxSize)
        return false;
    // L.data[L.length++] = t;
    for (int i = L.length; i >= pos; i--)
        L.data[i + 1] = L.data[i];
    L.data[pos] = t;
    L.length++;
    L.data[0] = L.data[1]; //哨兵

    return true;
}

bool DeleteList(SqList &L, int pos, int t)
{
    if (L.length == 0)
        return false;
    t = L.data[pos];
    while (pos < L.length)
        L.data[pos++] = L.data[pos + 1];
    L.length--;
    L.data[0] = L.data[1]; //哨兵
    return true;
}

int LocateElem(SqList L, int t)
{
    if (L.length == 0)
        return -1;
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == t)
            return i;
    return -1;
}

bool PrintList(SqList L)
{
    for (int i = 1; i <= L.length; i++)
        printf("L[%d] = %d\n", i, L.data[i]);
    return true;
}

/* 

        希尔排序

 */
void ShellSort(SqList &L, int length)
{
    //希尔排序中A[0]元素仅作为暂存单元，不作为哨兵参与比较
    for (int dk = length / 2; dk >= 1; dk /= 2)
    {
        for (int i = dk + 1; i <= length; ++i)
        {
            if (L.data[i] < L.data[i - dk])
            {
                L.data[0] = L.data[i];
                int j;
                for (j = i - dk; j > 0 && L.data[0] < L.data[j]; j -= dk)
                    L.data[j + dk] = L.data[j];
                L.data[j + dk] = L.data[0];
            }
        }
    }
}

/* 

        主函数功能测试模块

 */
int main()
{
    SqList L;
    InitList(L);
    int temp;
    for (int i = 9; i > 0; i--)
        InsertList(L, 10 - i, i);

    PrintList(L);
    printf("\n");

    // DeleteList(L, 4, temp);
    // PrintList(L);
    // printf("\n");

    ShellSort(L, L.length);
    PrintList(L);
    printf("\n");

    return 0;
}