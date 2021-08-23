/*

        CopyRight By Aphcity
        2021年8月23日

*/

#include <stdio.h>

#define MaxSize 10

typedef struct SqList
{
    int data[MaxSize];
    int length;
} SqList;

bool InitList(SqList &L);
bool InsertList(SqList &L, int t);
bool DeleteList(SqList &L, int &t);
int LocateElem(SqList &L, int t);
bool PrintList(SqList L);

bool InitList(SqList &L)
{
    L.length = 0;
    return true;
}

bool InsertList(SqList &L, int t)
{
    if (L.length == MaxSize)
        return false;
    L.data[L.length++] = t;
    return true;
}

bool DeleteList(SqList &L, int pos, int t)
{
    if (L.length == 0)
        return false;
    t = L.data[--pos];
    while (pos < L.length)
        L.data[pos++] = L.data[pos + 1];
    L.length--;
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
    for (int i = 0; i < L.length; i++)
        printf("L[%d] = %d\n", i, L.data[i]);
    return true;
}

/* 

        11统考两串有序数组中位数算法

 */

int FindCenter(SqList L1, SqList L2)
{
    int L1Right = L1.length,
        L1Left = 1,
        L2Right = L2.length,
        L2Left = 1,
        L1Mid = (L1Right + 1 - L1Left) / 2,
        L2Mid = (L2Right + 1 - L2Left) / 2;

    while (L1Mid != L1Left || L2Mid != L2Left)
    {
        L1Mid = (L1Right + L1Left) / 2;
        L2Mid = (L2Right + L2Left) / 2;
        if (L1.data[L1Mid - 1] == L2.data[L2Mid - 1])
            return L1Mid;
        if (L1.data[L1Mid - 1] < L2.data[L2Mid - 1])
        {
            L1Left = L1Mid;
            L2Right = L2Mid;
        }
        if (L2.data[L2Mid - 1] < L1.data[L1Mid - 1])
        {
            L2Left = L2Mid;
            L1Right = L1Mid;
        }
    }

    if (L1.data[L1Mid - 1] < L2.data[L2Mid - 1])
        return L1Mid;
    else
        return L2Mid;
}

/* 

        主函数功能测试模块

 */

int main()
{
    SqList L, LL;
    InitList(L);
    InitList(LL);
    int temp;
    for (int i = 1; i < 9; i++)
    {

        InsertList(L, i * 2 - 1);
        InsertList(LL, i * 2);
    }

    PrintList(L);
    printf("\n");

    PrintList(LL);
    printf("\n");

    // DeleteList(L, 4, temp);
    // PrintList(L);
    // printf("\n");

    printf("%d\n", FindCenter(L, LL));
    //PrintList(L);
    printf("\n");
    return 0;
}