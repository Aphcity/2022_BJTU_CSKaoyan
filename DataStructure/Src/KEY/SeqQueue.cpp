/*

        CopyRight By Aphcity
        2021年11月2日

*/

#include <stdio.h>
#include <stdlib.h>

/* 

        顺序(循环队列)结构

 */

#define ElemType int
#define MAXLENGTH 20

typedef struct SeqQueue
{
    ElemType data[MAXLENGTH];
    int front;
    int rear;
} SeqQueue;

bool InitSeqQueue(SeqQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    return true;
}

bool IsSeqQueueEmpty(SeqQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    return false;
}

//✅✅✅✅✅✅✅循环队列判满条件✅✅✅✅✅✅✅
bool IsSeqQueueFULL(SeqQueue Q)
{
    if (Q.front == (Q.rear + 1) % MAXLENGTH)
        return true;
    return false;
}

bool InsertSeqQueue(SeqQueue &Q, int num)
{
    if (IsSeqQueueFULL(Q))
        return false;
    Q.data[Q.rear++] = num;
    return true;
}

bool DeleteSeqQueue(SeqQueue &Q, int &num)
{
    if (IsSeqQueueEmpty(Q))
        return false;
    num = Q.data[Q.front++];
    return true;
}
