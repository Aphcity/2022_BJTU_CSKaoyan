/*

        CopyRight By Aphcity
        2021年11月06日

*/

#include <stdio.h>

#define MaxSize 10
#define ElemType int

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

        堆排序

 */
/**
 * 根据表L建立大根堆
 * @param L
 * @param length
 */
void BuildMaxHeap(SqList &L, int length);
/**
 * 大根堆对元素K为跟的子树进行调整
 * @param L
 * @param k
 * @param length
 */
void HeadAdjust(SqList &L, int k, int length);
//元素交换
void SWAP(ElemType &a, ElemType &b);
/**
 * 大根堆堆排序 
 */
void MaxHeapSort(SqList &L, int length)
{
    //堆排序中A[0]元素仅作为暂存单元，不作为哨兵参与比较
    BuildMaxHeap(L, length);
    for (int i = length; i > 1; i--)
    {
        SWAP(L.data[i], L.data[1]);
        HeadAdjust(L, 1, i - 1);
    }
}

void BuildMaxHeap(SqList &L, int length)
{
    for (int i = length / 2; i > 0; i--)
        HeadAdjust(L, i, length); //从第一个分支结点开始调整二叉树
}

void HeadAdjust(SqList &L, int k, int length)
{
    L.data[0] = L.data[k];                  //暂存根节点元素
    for (int i = 2 * k; i < length; i *= 2) //遍历k的所有子树
    {
        if (i < length && L.data[i] < L.data[i + 1]) //对比k结点的左右孩子，取大者为i，接着对i的子树进行遍历
            i++;
        if (L.data[0] >= L.data[i]) //当堆顶元素更大时，不进行调整
            break;
        else //孩子更大，i所指孩子结点作为新的跟结点
        {
            L.data[k] = L.data[i];
            k = i;
        }
    }
    L.data[k] = L.data[0]; //根节点取出，作为i所指结点
}
void SWAP(ElemType &a, ElemType &b)
{
    ElemType temp = a;
    a = b;
    b = temp;
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

    MaxHeapSort(L, L.length);
    PrintList(L);
    printf("\n");

    return 0;
}