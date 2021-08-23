/*

        CopyRight By Aphcity
        2021年8月17日

*/

#include <stdio.h>

#define MaxSize 10
typedef struct SqQueue
{
    int tag;
    char data[MaxSize];
    int front;
    int rear;
} SqQueue;

typedef struct SqStack
{
    int top;
    char data[MaxSize];
} SqStack;

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

        顺序栈基本功能框架

*/

bool InitStack(SqStack &S);
bool Push(SqStack &S, char t);
bool Pop(SqStack &S, char &t);
bool GetTop(SqStack &S, char &t);
bool StackEmpty(SqStack S);
bool PrintStack(SqStack S);

bool InitStack(SqStack &S)
{
    S.top = -1;
    return true;
}

bool Push(SqStack &S, char t)
{
    if (S.top < MaxSize)
    {
        S.data[++S.top] = t;
        return true;
    }
    return false;
}

bool Pop(SqStack &S, char &t)
{
    if (!StackEmpty(S))
    {
        t = S.data[S.top--];
        return true;
    }
    return false;
}

bool GetTop(SqStack &S, char &t)
{
    if (!StackEmpty(S))
    {
        t = S.data[S.top];
        return true;
    }
    return false;
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    return false;
}

bool PrintStack(SqStack S)
{
    if (StackEmpty(S))
        return false;
    printf("In the Stack is:\n");
    for (int i = 0; i <= S.top; i++)
    {
        printf("S[%d] = %c\n", i, S.data[i]);
    }
    printf("Completed!\n");
    return true;
}

/* 

        使用栈的倒置队列算法

 */

bool ReverseQueue(SqQueue &Q)
{
    if (QueueEmpty(Q))
        return false;

    SqStack parklot;
    InitStack(parklot);
    char temp;
    while (!QueueEmpty(Q))
    {
        DeQueue(Q, temp);
        Push(parklot, temp);
    }
    while (!StackEmpty(parklot))
    {
        Pop(parklot, temp);
        EnQueue(Q, temp);
    }

    return true;
}

/* 

        主函数模块

*/

bool TestApplication()
{
    SqQueue Q;
    InitQueue(Q);
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
    ReverseQueue(Q);
    PrintQueue(Q);
    return true;
}

int main()
{
    TestApplication();
    return 0;
}