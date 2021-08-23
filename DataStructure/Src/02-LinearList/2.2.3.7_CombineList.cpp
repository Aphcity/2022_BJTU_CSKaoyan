/*

        CopyRight By Aphcity
        2021年8月22日

*/

#include <stdio.h>

#define MaxSize 20

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

bool InsertList(SqList &L, int pos, int t)
{
    if (L.length == MaxSize)
        return false;
    // L.data[L.length++] = t;
    for (int i = L.length; i > pos; i--)
        L.data[i] = L.data[i - 1];
    L.data[pos - 1] = t;
    L.length++;

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

        空间复杂度 为 O(1) 的逆置表算法

 */

SqList CombineList(SqList &L1, SqList L2)
{
    if (L1.length == 0 || L2.length == 0)
    {
        printf("ERROR!\n");
        return L1;
    }
    int temp = 0;
    for (int i = 0; i < L1.length; i++)
        for (int j = 0; L2.data[j] < L1.data[i]; j++)
        {
            InsertList(L1, i + 1, L2.data[j]);
            DeleteList(L2, j - 1, temp);
        }

    return L1;
}

/* 

        主函数功能测试模块

 */

int main()
{
    SqList L1, L2;
    InitList(L1);
    InitList(L2);
    int temp;
    for (int i = 0; i < 8; i++)
    {
        InsertList(L1, i + 1, i / 3);
        InsertList(L2, i + 1, i / 4);
    }

    PrintList(L1);
    printf("\n");

    PrintList(L2);
    printf("\n");
    // DeleteList(L, 4, temp);
    // PrintList(L);
    // printf("\n");

    PrintList(CombineList(L1, L2));
    printf("\n");
    return 0;
}