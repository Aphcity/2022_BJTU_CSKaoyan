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

        字符串中心对称问题

*/

bool Symmetry(char *input)
{
    if (input[0] == '\0')
        return false;

    int length = 0;
    for (int i = 0; input[i] != '\0'; i++)
        length++;

    SqStack frontHalf;
    InitStack(frontHalf);
    char temp = '0';

    for (int i = 0; i < (length / 2); i++)
        Push(frontHalf, input[i]);
    for (int i = (length + 1) / 2; i < length; i++)
    {
        Pop(frontHalf, temp);
        if (temp != input[i])
            return false;
    }

    return true;
}

/*

        主函数执行部分

*/

bool TestApplication()
{
    char input[MaxSize] = "xxxx";
    if (Symmetry(input))
        printf("Yee Yee Ass Haircut!\n");
    else
        printf("Shit Bro!\n");
    return true;
}

int main()
{
    TestApplication();
    return 0;
}