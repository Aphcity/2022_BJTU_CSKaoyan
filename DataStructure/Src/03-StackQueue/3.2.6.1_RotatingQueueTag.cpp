/*

        CopyRight By Aphcity
        2021年8月17日

*/

#include <stdio.h>

#define MaxSize 10
typedef struct
{
    int tag;
    char data[MaxSize];
    int front;
    int rear;
} SqQueue;
/*

        循环队列基本功能框架

*/
bool InitQueue(SqQueue Q);
bool EnQueue(SqQueue &Q, char t);
bool DeQueue(SqQueue &Q, char &t);
bool GetHead(SqQueue Q, char &t);
bool QueueEmpty(SqQueue Q);
bool QueueFull(SqQueue Q);
bool PrintQueue(SqQueue Q);

bool InitQueue(SqQueue Q)
{
    Q.tag = 0;   // 0 For Empty // 1 For Full // Set 0 When DEL,Set 1 When ADD
    Q.front = 0; //Start With Front And Rear equal at 0
    Q.rear = 0;
    return true;
}

bool EnQueue(SqQueue &Q, char t)
{
    if (QueueFull(Q))
        return false;
    Q.data[Q.rear++] = t;
    Q.rear %= MaxSize;
    Q.tag = 1;
    return true;
}

bool DeQueue(SqQueue &Q, char &t)
{
    if (QueueEmpty(Q))
        return false;
    t = Q.data[Q.front++];
    Q.front %= MaxSize;
    Q.tag = 0;
    return true;
}

bool GetHead(SqQueue Q, char &t)
{
    if (QueueEmpty(Q))
        return false;
    t = Q.data[Q.front];
    return true;
}

bool QueueEmpty(SqQueue Q)
{
    if (Q.tag == 0 && Q.front == Q.rear)
        return true;
    return false;
}

bool QueueFull(SqQueue Q)
{
    if (Q.tag == 1 && Q.front == Q.rear)
        return true;
    return false;
}

bool PrintQueue(SqQueue Q)
{
    if (QueueEmpty(Q))
        return false;
    printf("The Queue is :\n");
    for (int i = Q.front; i != Q.rear; ++i %= MaxSize)
        printf("Q[%d] = %c\n", i, Q.data[i]);
    printf("Completed!\n");
    return true;
}

/* 

        主函数模块

*/

bool TestApplication()
{
    SqQueue Q;
    char temp;
    EnQueue(Q, '1');
    EnQueue(Q, '2');
    EnQueue(Q, '3');
    EnQueue(Q, '4');
    EnQueue(Q, '5');
    EnQueue(Q, '6');
    EnQueue(Q, '7');
    EnQueue(Q, '8');
    EnQueue(Q, '9');
    DeQueue(Q, temp);
    DeQueue(Q, temp);
    DeQueue(Q, temp);
    DeQueue(Q, temp);
    DeQueue(Q, temp);
    EnQueue(Q, '=');
    EnQueue(Q, '+');
    EnQueue(Q, '-');
    EnQueue(Q, '*');
    PrintQueue(Q);
    return true;
}

int main()
{
    TestApplication();
    return 0;
}