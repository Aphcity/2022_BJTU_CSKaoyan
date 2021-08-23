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
//括号匹配问题

/**基本模块**/
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

/**实现模块**/
bool BracketPair(char *input)
{
    SqStack temp;
    char paired;
    InitStack(temp);
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
            if (StackEmpty(temp))
                return false;
            else
                switch (input[i])
                {
                case ')':
                    if (temp.data[temp.top] == '(')
                        Pop(temp, paired);
                    else
                        return false;
                    break;
                case ']':
                    if (temp.data[temp.top] == '[')
                        Pop(temp, paired);
                    else
                        return false;
                    break;
                case '}':
                    if (temp.data[temp.top] == '{')
                        Pop(temp, paired);
                    else
                        return false;
                    break;
                default:
                    return false;
                    break;
                }
        }
        else if (input[i] == '(' || input[i] == '[' || input[i] == '{')
            Push(temp, input[i]);
        else
        {
            if (StackEmpty(temp))
                return false;
            return true;
        }
    }
    return true;
}
/**测试模块**/
//打印整个栈
void PrintStack(SqStack S)
{
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top >= 0)
    { //注意判空的条件
        printf("S[%d]=%d\n", S.top, S.data[S.top--]);
    }
    printf("栈打印完毕\n");
}

void TestQueueApplication()
{
    printf("开始测试\n");
    char input[MaxSize] = "{[]}";
    if (BracketPair(input))
        printf("Yee Yee Ass Haircut\n");
    else
        printf("Shit Bro\n");
}
/**测试模块**/

int main()
{
    TestQueueApplication();
    return 0;
}
