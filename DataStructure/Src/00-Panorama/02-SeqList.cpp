/*

        CopyRight By Aphcity
        2021年10月06日

*/

#include <stdio.h>
#include <stdlib.h>

#define Maxsize 20

/* 

        顺序表定义及基本操作

 */

typedef struct SqList
{
    int data[Maxsize];
    int length;
} SqList;

bool InitSqList(SqList &L)
{
    L.length = 0;
    return true;
}

bool IsEmptySqList(SqList L)
{
    if (L.length == 0)
        return true;

    return false;
}

bool InsertSqList(SqList &L, int pos, int num)
{
    if (L.length == Maxsize)
        return false;

    for (int i = L.length; i > pos; i--)
        L.data[i] = L.data[i - 1];
    L.data[pos - 1] = num;
    L.length++;

    return true;
}

bool DeleteSqList(SqList &L, int pos, int num)
{
    if (IsEmptySqList(L) || L.length < pos)
        return false;
    num = L.data[pos - 1];
    while (pos < L.length)
    {
        L.data[pos - 1] = L.data[pos];
        pos++;
    }
    L.length--;
    return true;
}

bool PrintSqList(SqList L)
{
    if (IsEmptySqList(L))
    {
        printf("FUCK ! IT'S EMPTY !\n");
        return false;
    }

    printf("THE DAMN LIST IS :\n");

    for (int i = 0; i < L.length; i++)
        printf("%d\n", L.data[i]);

    return true;
}

/* 

        顺序表原地逆置

 */

bool Reverse_SqList(SqList &L)
{

    if (IsEmptySqList(L))
        return false;

    int temp = 0;
    for (int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }

    return true;
}

/* 

        顺序查找(无哨兵)

 */

int SeqFind_1(SqList L, int num)
{
    if (IsEmptySqList(L))
        return 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == num)
            return i + 1;
    }
    return 0;
}

int SeqFind_2(SqList L, int num)
{

    if (IsEmptySqList(L))
        return 0;
    int i = 0;
    for (i = 0; i < L.length && L.data[i] != num; i++)
        ;

    return i == L.length ? 0 : i + 1;
}

/* 

        折半查找

 */

int Binary_Search(SqList L, int num)
{
    if (IsEmptySqList(L))
        return 0;
    int low = 0, high = L.length - 1, mid = (low + high) / 2;
    while (low <= high)
    {
        if (L.data[mid] == num)
            return mid + 1;
        if (L.data[mid] < num)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    return 0;
}

/* 

        主函数功能测试

 */

int main()
{
    SqList L;
    InitSqList(L);

    //新建升序表
    for (int i = 1; i < Maxsize / 2; i++)
        InsertSqList(L, i, i + 3);
    PrintSqList(L);

    //折半查找特定元素
    printf("BINARY FINDED : %d\n", Binary_Search(L, 6));
    printf("BINARY FINDED : %d\n", Binary_Search(L, 14));

    //逆置得到降序表
    Reverse_SqList(L);
    PrintSqList(L);

    //删除特定元素
    int temp = 0;

    DeleteSqList(L, 5, temp);
    PrintSqList(L);

    //顺序查找特定元素
    printf("SEQUENT FINDED : %d\n", SeqFind_1(L, 6));
    printf("SEQUENT FINDED : %d\n", SeqFind_2(L, 9));

    return 0;
}