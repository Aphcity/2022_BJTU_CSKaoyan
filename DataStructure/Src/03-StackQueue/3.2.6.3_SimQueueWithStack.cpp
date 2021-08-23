/*

        CopyRight By Aphcity
        2021年8月16日

*/

#include <stdio.h>

#define MaxSize 10
typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

bool InitStack(SqStack &S);
bool Push(SqStack &S, char t);
bool Pop(SqStack &S, char &t);
bool GetTop(SqStack &S, char &t);
bool StackEmpty(SqStack S);
bool PrintStack(SqStack S);

/*

        顺序栈基本功能框架

*/

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

bool StackFull(SqStack S)
{
    if (S.top == MaxSize - 1)
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

        双栈模拟队列问题

*/

bool Enqueue(SqStack &S1, SqStack &S2, char t)
{
    char temp;
    while (!StackEmpty(S2) && !StackFull(S1))
    {
        Pop(S2, temp);
        Push(S1, temp);
    }
    Push(S1, t);
    return true;
}

bool Dequeue(SqStack &S1, SqStack &S2, char &t)
{
    char temp;
    while (!StackEmpty(S1) && !StackFull(S2))
    {
        Pop(S1, temp);
        Push(S2, temp);
    }
    Pop(S2, t);
    return true;
}

bool QueueEmpty(SqStack S1, SqStack S2)
{
    if (StackEmpty(S1) && StackEmpty(S2))
        return true;
    return false;
}
/*

        主函数执行部分

*/

bool TestApplication()
{
    return true;
}

int main()
{
    // TestApplication();
    return 0;
}