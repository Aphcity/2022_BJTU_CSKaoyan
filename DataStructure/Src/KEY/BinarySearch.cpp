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
bool InsertList(SqList &L, int pos, int t);
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

        折半查找

 */

int BinarySearch(SqList L, int x)
{
    if (L.length == 0)
        return -1;
    int leftLimit = 0, rightLimit = L.length - 1;
    int mid;
    while (leftLimit <= rightLimit)
    {
        int mid = (leftLimit + rightLimit) / 2;
        if (L.data[mid] == x)
        {
            x = mid + 1;
            return mid + 1;
        }

        else if (L.data[mid] > x)
            rightLimit = mid - 1;
        else
            leftLimit = mid + 1;
    }
    return -1;
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
        InsertList(L, i + 1, i);

    PrintList(L);
    printf("\n");

    // DeleteList(L, 4, temp);
    // PrintList(L);
    // printf("\n");

    printf("%d\n", BinarySearch(L, 4));
    printf("%d\n", BinarySearch(L, 7));
    printf("%d\n", BinarySearch(L, 57));
    return 0;
}