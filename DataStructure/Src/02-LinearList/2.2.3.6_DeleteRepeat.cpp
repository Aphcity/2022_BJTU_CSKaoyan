/*

        CopyRight By Aphcity
        2021年8月22日

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

        删除表内重复元素算法

 */

bool DeleteRepeat(SqList &L)
{
    if (L.length == 0)
        return false;

    int data[MaxSize];
    int temp = 0;
    for (int i = 0; i < L.length; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            while (L.data[i] == data[j])
                DeleteList(L, i + 1, temp);
        }
        data[i] = L.data[i];
    }
    return true;
}

/* 

        主函数功能测试模块

 */

int main()
{
    SqList L;
    InitList(L);
    int temp;
    for (int i = 0; i < 8; i++)
        InsertList(L, i / 3);

    PrintList(L);
    printf("\n");

    // DeleteList(L, 4, temp);
    // PrintList(L);
    // printf("\n");

    DeleteRepeat(L);
    PrintList(L);
    printf("\n");
    return 0;
}