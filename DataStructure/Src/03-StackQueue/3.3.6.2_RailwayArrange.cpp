#include <stdio.h>

/**定义模块**/
#define MaxSize 10
typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

//函数声明
//以下都是基础操作定义以及实现的方式和前面一样
void InitStack(SqStack &S);    //初始化
bool Push(SqStack &S, char t); //入栈
bool Pop(SqStack &S, char &x); //出栈,并打印出栈顶元素
void PrintStack(SqStack S);    //打印栈，输出测试
bool StackEmpty(SqStack S);    //判栈空
//以上都是基础操作定义以及实现的方式和前面一样
//表达式求值问题

/**实现模块**/
void InitStack(SqStack &S)
{
    S.top = -1; //这种初始化的方式，栈顶指针始终指向栈顶元素
}

bool Push(SqStack &S, char t)
{
    if (S.top == MaxSize - 1)
        return false; //栈满
    S.data[++S.top] = t;
    //等价下面两个语句
    //S.top+=1;//先将栈顶指针指向下一个位置
    //S.data[S.top]=t;//再填充元素
    return true;
}

bool Pop(SqStack &S, char &x)
{
    //判断
    if (S.top == -1)
        return false; //栈空报错
    x = S.data[S.top--];
    //    等价于下面
    //    x=S.data[S.top];//先取元素
    //    S.top -=1;//再改指针
    return true;
}

bool Read(SqStack &S, char &x)
{
    //判断
    if (S.top == -1)
        return false; //栈空报错
    x = S.data[S.top];
    return true;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

void PrintStack(SqStack S)
{
    printf("火车队列如下：\n");
    printf(S.data);
    printf("\n");
}

/**实现模块**/
bool Arrange(char *train)
{
    SqStack Hard, Arranged;
    InitStack(Hard);
    InitStack(Arranged);
    char temp;
    for (int i = 0; train[i] != '\0'; i++)
    {
        if (train[i] == 'H')
            Push(Hard, train[i]);
        else if (train[i] == 'S')
            Push(Arranged, train[i]);
        else
            return false;
    }
    while (!StackEmpty(Hard))
    {
        Pop(Hard, temp);
        Push(Arranged, temp);
    }
    PrintStack(Arranged);
    return true;
}
/**测试模块**/
bool test()
{
    char train[MaxSize] = "HHSSHSHS";
    if (Arrange(train))
        printf("Yee Yee Ass Haircut");
    else
        printf("SHIT BRO");
    return true;
}
int main()
{
    test();
    return 0;
}
