/*

        CopyRight By Aphcity
        2021年8月16日

*/

#include <stdio.h>

#define MaxSize 20

#define s1 "s1"
#define s2 "s2"

typedef struct
{
    char data[MaxSize];
    int s1Top;
    int s2Top;
} SqStack;

// bool InitStack(SqStack &S);
// bool Push(SqStack &S, char t);
// bool Pop(SqStack &S, char &t);
// bool GetTop(SqStack &S, char &t);
bool StackEmpty(SqStack S, char *pos);
// bool PrintStack(SqStack S);

/*

        共享顺序栈基本功能框架

*/

bool InitStack(SqStack &S)
{
    S.s1Top = -1;
    S.s2Top = MaxSize;
    return true;
}

bool Push(SqStack &S, char *pos, char t)
{
    if (S.s1Top + 1 < S.s2Top)
    {
        if (pos == s1)
        {
            S.data[++S.s1Top] = t;
            return true;
        }
        if (pos == s2)
        {
            S.data[--S.s2Top] = t;
            return true;
        }
    }
    return false;
}

bool Pop(SqStack &S, char *pos, char &t)
{
    if (!StackEmpty(S, pos))
    {
        if (pos == s1)
        {
            t = S.data[S.s1Top--];
            return true;
        }
        if (pos == s2)
        {
            t = S.data[S.s2Top++];
            return true;
        }
    }
    return false;
}

bool GetTop(SqStack &S, char *pos, char &t)
{
    if (!StackEmpty(S, pos))
    {
        if (pos == s1)
        {
            t = S.data[S.s1Top];
            return true;
        }
        if (pos == s2)
        {
            t = S.data[S.s2Top];
            return true;
        }
    }
    return false;
}

bool StackEmpty(SqStack S, char *pos)
{
    if (pos == s1 && S.s1Top == -1)
        return true;
    if (pos == s2 && S.s2Top == MaxSize)
        return true;
    return false;
}

bool PrintStack(SqStack S, char *pos)
{
    if (StackEmpty(S, pos))
        return false;
    printf("In the %s Stack is:\n", pos);
    if (pos == s1)
        for (int i = 0; i <= S.s1Top; i++)
            printf("s1[%d] = %c\n", i, S.data[i]);
    if (pos == s2)
        for (int i = 0; MaxSize - 1 - i >= S.s2Top; i++)
            printf("s2[%d] = %c\n", i, S.data[MaxSize - 1 - i]);
    printf("Completed!\n");
    return true;
}

/*

        主函数执行部分

*/

bool TestApplication()
{
    SqStack S;
    InitStack(S);
    char temp;
    Push(S, s1, '1');
    Push(S, s1, '1');
    Push(S, s1, '3');
    Push(S, s1, '1');
    Push(S, s1, '5');
    Push(S, s1, '1');
    Push(S, s1, '7');
    Push(S, s1, '1');
    Push(S, s1, '9');
    Push(S, s2, '9');
    Push(S, s2, '1');
    Push(S, s2, '7');
    Push(S, s2, '1');
    Push(S, s2, '5');
    Push(S, s2, '1');
    Push(S, s2, '3');
    Push(S, s2, '1');
    Push(S, s2, '1');
    Pop(S, s1, temp);
    Pop(S, s1, temp);
    Pop(S, s1, temp);
    Pop(S, s1, temp);
    Pop(S, s2, temp);
    Pop(S, s2, temp);
    Pop(S, s2, temp);
    Pop(S, s2, temp);
    Pop(S, s2, temp);
    PrintStack(S, s2);
    PrintStack(S, s1);
    /* if (1)
        printf("Yee Yee Ass Haircut!\n");
    else
        printf("Shit Bro!\n"); */
    return true;
}

int main()
{
    TestApplication();
    return 0;
}