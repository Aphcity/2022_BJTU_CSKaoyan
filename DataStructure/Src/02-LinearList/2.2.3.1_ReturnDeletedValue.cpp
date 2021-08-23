/*

        CopyRight By Aphcity
        2021年8月17日

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

        删除顺序表中的最小元素并通过函数返回删除值

 */

int DeleteMinium(SqList &L)
{
    if (L.length == 0)
        return -1;
    int minium = L.data[0], minPos = 0;
    for (int i = 0; i < L.length; i++)
        if (minium > L.data[i])
        {
            minium = L.data[i];
            minPos = i;
        }
    if (DeleteList(L, minPos, minium))
        return minium;
    return -1;
}

int main()
{
    SqList L;
    InitList(L);
    int temp;
    for (int i = 0; i < 8; i++)
        InsertList(L, i);

    PrintList(L);
    printf("\n");

    DeleteList(L, 4, temp);
    PrintList(L);
    printf("\n");

    DeleteMinium(L);
    PrintList(L);
    printf("\n");
    return 0;
}