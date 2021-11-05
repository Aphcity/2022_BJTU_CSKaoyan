/*

        CopyRight By Aphcity
        2021年11月05日

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

        (哨兵)直接插入排序

 */
void InsertSort(SqList &L, int length)
{
    for (int i = 2; i <= length; i++) //从L[2]到L[n]依次扫描
    {
        if (L.data[i] < L.data[i - 1]) //当扫描位置元素发生错序时
        {
            int j;
            L.data[0] = L.data[i];                      //哨兵暂时存放扫描到的位置
            for (j = i - 1; L.data[0] < L.data[j]; --j) //寻找比哨兵小的第一个位置
                L.data[j + 1] = L.data[j];              //从末尾开始依次后置元素
            L.data[j + 1] = L.data[0];                  //将哨兵元素插入
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

    InsertSort(L, L.length);
    PrintList(L);
    printf("\n");

    return 0;
}