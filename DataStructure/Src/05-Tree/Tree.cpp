/*

        CopyRight By Aphcity
        2021年10月30日

*/

#include <stdio.h>
#include <stdlib.h>

/* 

        🌳的孩子兄弟表示法基本结构及操作

 */

#define ElemType int

typedef struct CSNode
{
    ElemType data;       //🌳的节点数据
    CSNode *firstChild;  //🌳的第一个孩子
    CSNode *nextSibling; //🌳的下一个表亲
} CSNode, *CSTree;

/* 

        🌳的孩子兄弟表示法

 */

bool IsEmptyCSTree(CSTree T)
{
    if (T == NULL)
        return true;
    return false;
}

/* 

        🌳的孩子兄弟表示法求叶子结点个数

 */

int N0_NUMBER(CSTree T)
{
    if (IsEmptyCSTree(T))
        return 1;
    int count = 0; //count存放叶子结点个数，n0
    //printf("%d", T->data); //输出🌳的根节点数据
    //开始遍历子树
    count += N0_NUMBER(T->nextSibling);
    while (T->firstChild)
    {
        count += N0_NUMBER(T->firstChild);
    }
    return count - 1;
}

/* 

        🌳的孩子兄弟表示法遍历

 */
