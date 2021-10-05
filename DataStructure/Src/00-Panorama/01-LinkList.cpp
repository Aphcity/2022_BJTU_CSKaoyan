/*

        CopyRight By Aphcity
        2021年10月05日

*/

#include <stdio.h>
#include <stdlib.h>

/*

    单链表定义及基本操作

 */

typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;

bool Init_LinkList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); //分配头结点
    L->next = NULL;                     //初始化,头指针指向NULL为空
    return true;
}

bool IsEmptyLinkList(LinkList L)
{
    if (L->next == NULL)
        return true;
    return false;
}

bool HeadInsert_LinkList(LinkList &L, int x)
{
    LNode *NextNode;                           //新建新节点
    NextNode = (LNode *)malloc(sizeof(LNode)); //分配空间
    NextNode->next = L->next;                  //新插入节点指向原首位结点
    NextNode->data = x;                        //新插入节点赋值
    L->next = NextNode;                        //头结点指向新结点
    return true;
}

bool TailInsert_LinkList(LinkList &L, int x)
{
    LNode *OriginHead, *NextNode;
    NextNode = (LNode *)malloc(sizeof(LNode));
    OriginHead = L;
    while (OriginHead->next != NULL)
        OriginHead = OriginHead->next;
    OriginHead->next = NextNode;

    NextNode->data = x;
    NextNode->next = NULL;

    return true;
}

bool Print_LinkList(LinkList L)
{
    if (IsEmptyLinkList(L))
    {
        printf("EMPTY LIST ! FUCK ! \n");
        return false;
    }

    printf("THE DAMN LIST IS:\n");

    while (L->next != NULL)
    {
        L = L->next;
        printf("%d\n", L->data);
    }
    return true;
}

/* 

        单链表原地逆置
        P38 2.3.7 2.5

 */

//  解法一  遍历头插法
bool Reverse_HeadInsert(LinkList &L)
{
    if (IsEmptyLinkList(L))
        return false;
    LNode *Origin = L->next, *New;
    L->next = NULL;

    /* 

    //  这个由于调用了HeadInsert,空间复杂度并不为一

    while (OriginList->next != NULL)
    {
        HeadInsert_LinkList(L, OriginList->data);
        OriginList = OriginList->next;
    }
    HeadInsert_LinkList(L, OriginList->data);

 */

    while (Origin != NULL)
    {
        New = Origin;
        Origin = Origin->next;
        New->next = L->next;
        L->next = New;
    }

    return true;
}

//  解法二  遍历中指针回溯
bool Reverse_PrePointer(LinkList &L)
{
    if (IsEmptyLinkList(L))
        return false;
    LNode *Origin = L->next, *Pre = L, *Next = Origin->next;
    Origin->next = NULL;
    while (Next != NULL)
    {

        L->next = Next;
        Pre = Origin;
        Origin = Next;
        Next = Next->next;
        Origin->next = Pre;
    }

    return true;
}

/* 

        主函数测试部分

 */

int main()
{
    //新建一个单链表

    LinkList L;
    Init_LinkList(L);
    for (int i = 0; i < 5; i++)
        HeadInsert_LinkList(L, i);
    for (int i = 5; i < 10; i++)
        TailInsert_LinkList(L, i);
    Print_LinkList(L);

    Reverse_HeadInsert(L);
    Print_LinkList(L);

    Reverse_PrePointer(L);
    Print_LinkList(L);
    return 0;
}