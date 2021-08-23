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

/**实现模块**/
int isp(char t) //in stock priority
{
    if (t == '#')
        return 0;
    else if (t == '(')
        return 1;
    else if (t == '+' || t == '-')
        return 3;
    else if (t == '*' || t == '/')
        return 5;
    else if (t == ')')
        return 6;
    else
        return -1;
}

int icp(char t) //in coming priority
{
    if (t == '#')
        return 0;
    else if (t == '(')
        return 6;
    else if (t == '*' || t == '/')
        return 4;
    else if (t == '+' || t == '-')
        return 2;
    else if (t == ')')
        return 1;
    else
        return -1;
}

bool doTranslate(char *input, int length, SqStack &output)
{
    SqStack opera;
    InitStack(opera);
    char temp;
    for (int i = 0; i < length; i++)
    {
        if (input[i] >= '0' && input[i] <= '9') //数字直接加入表达式
            output.data[++output.top] = input[i];
        else if (input[i] == '(') //左括号进行入栈
            Push(opera, input[i]);
        else if (input[i] == ')')  //右括号进行判短
            if (StackEmpty(opera)) //运算符栈为空时,报错
                return false;
            else
            {
                while (opera.data[opera.top] != '(') //非空时依次输出栈中运算符直至(,并删除(
                    Pop(opera, output.data[++output.top]);
                if (opera.data[opera.top] == '(')
                    Pop(opera, temp);
            }
        else if (StackEmpty(opera)) //若是其他运算符,当栈中为空时直接入栈
            Push(opera, input[i]);
        else
        {
            if (icp(input[i]) > isp(opera.data[opera.top])) //非空栈,判断入栈运算符和栈内运算符优先级,入栈更高时运算符入栈
                Push(opera, input[i]);
            else
            {
                while (icp(input[i]) <= isp(opera.data[opera.top]) && opera.top != '(') //栈内运算符优先级不低于入栈运算符时,输出所有不低于入栈优先级的运算符到表达式
                    Pop(opera, output.data[++output.top]);
                Push(opera, input[i]);
            }
        }
    }
    while (!StackEmpty(opera)) //最后将栈内所有运算符依次输出
        Pop(opera, output.data[++output.top]);
    printf("后缀表达式为：");
    printf(output.data);
    printf("\n");
    return true;
}

bool doExecution(SqStack &output)
{
    SqStack number; //建立一个存放数据的栈
    InitStack(number);
    char a, b;
    for (int i = 0; i < output.top + 1; i++)
    {
        if (output.data[i] >= '0' && output.data[i] <= '9') //数字直接入栈,char转化为int时-48
            Push(number, output.data[i] - 48);
        else if (output.data[i] == '+' || output.data[i] == '-' || output.data[i] == '*' || output.data[i] == '/')
        {
            Pop(number, b); //弹出后操作数
            Pop(number, a); //弹出前操作数
                            //根据操作符匹配运算
            if (output.data[i] == '+')
            {
                a += b;
                Push(number, a);
            }
            if (output.data[i] == '-')
            {
                a -= b;
                Push(number, a);
            }
            if (output.data[i] == '*')
            {
                a *= b;
                Push(number, a);
            }
            if (output.data[i] == '/')
            {
                a /= b;
                Push(number, a);
            }
        }
    }

    if (!Pop(number, a))
        return false; //将最终结果弹出
    printf("计算结果为：%d\n", a);
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
    SqStack output;
    InitStack(output);
    int length = 0;
    char input[2 * MaxSize] = "1+3*(5-1)/4";
    for (int i = 0; input[i] != '\0'; i++)
        length++;
    doTranslate(input, length, output);
    doExecution(output);
}
/**测试模块**/

int main()
{
    TestQueueApplication();
    return 0;
}
