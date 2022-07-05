/*

        CopyRight By Aphcity
        2021年10月30日

*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define ElemType int

typedef struct SqList
{
    ElemType data[MaxSize];
    int length;
} SqList;

bool InitList(SqList &L);
/**
 * 顺序表插入元素
 * @param L
 * @param pos 插入位置
 * @param t 插入元素
 */
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

        快速排序

 */
/**
 * 划分操作
 * 将表L划分为满足大于，小于枢轴元素的两部分
 * @param low 左端下标，即为本次快速排序的枢轴元素
 * @param high 右端下标
 */
int Partition(SqList &L, int low, int high)
{
    ElemType pivot = L.data[low]; //左侧第一个元素作为枢轴，划分表
    while (low < high)            //一次快速排序
    {
        while (low < high && L.data[high] >= pivot) //寻找比枢轴小的元素移动到左端空缺
            --high;
        L.data[low] = L.data[high];
        while (low < high && L.data[low] <= pivot) //寻找比枢轴大的元素移动到右端空缺
            ++low;
        L.data[high] = L.data[low];
    }
    L.data[low] = pivot; //最后将枢轴元素放入最后的空缺（左端）
    return low;          //返回枢轴元素所在位置，以进行下一次快速排序划分
}
/**
 * 快速排序递归调用函数
 * 
 */
void QuickSort(SqList &L, int low, int high)
{
    if (low < high) //递归调用结束的条件，左端指针小于右端了
    {
        int pivotpos = Partition(L, low, high); //一次快速排序划分得到新的枢轴元素位置，将表划分为两部分
        QuickSort(L, low, pivotpos - 1);        //左表从左端到枢轴左侧元素再次递归地进行快速排序
        QuickSort(L, pivotpos + 1, high);       //右表从枢轴右侧元素到右端再次递归地进行快速排序
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
    for (int i = 0; i < 10; i++)
        InsertList(L, i + 1, (7 * i) % 10);
    PrintList(L);
    printf("\n");

    QuickSort(L, 0, L.length - 1);
    PrintList(L);

    return 0;
}