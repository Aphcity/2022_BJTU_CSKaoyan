#include <stdio.h>

/**定义模块**/
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;

//函数声明
//以下都是基础操作定义以及实现的方式和前面一样
void InitStack(SqStack &S);   //初始化
bool Push(SqStack &S, int t); //入栈
bool Pop(SqStack &S, int &x); //出栈,并打印出栈顶元素
void PrintStack(SqStack S);   //打印栈，输出测试
bool StackEmpty(SqStack S);   //判栈空
//以上都是基础操作定义以及实现的方式和前面一样
//表达式求值问题

/**实现模块**/
void InitStack(SqStack &S)
{
    S.top = -1; //这种初始化的方式，栈顶指针始终指向栈顶元素
}

bool Push(SqStack &S, int t)
{
    if (S.top == MaxSize - 1)
        return false; //栈满
    S.data[++S.top] = t;
    //等价下面两个语句
    //S.top+=1;//先将栈顶指针指向下一个位置
    //S.data[S.top]=t;//再填充元素
    return true;
}

bool Pop(SqStack &S, int &x)
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

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

void PrintStack(SqStack S)
{
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top >= 0)
    { //注意判空的条件
        printf("P[%d]=%d\n", S.top + 1, S.data[S.top--]);
    }
    printf("栈打印完毕\n");
}

/**实现模块**/

bool function(int x)
{
    SqStack storehouse;
    int temp;
    InitStack(storehouse);
    Push(storehouse, 1);
    Push(storehouse, 2 * x);
    while (storehouse.top < MaxSize - 1)
    {
        temp = 2 * x * storehouse.data[storehouse.top] - 2 * storehouse.top * storehouse.data[storehouse.top - 1];
        Push(storehouse, temp);
    }
    PrintStack(storehouse);
    return true;
}

/**测试模块**/

bool test()
{
    function(1);
    return true;
}

int main()
{
    test();
    return 0;
}
