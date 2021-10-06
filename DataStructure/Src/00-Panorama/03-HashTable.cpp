/*

        CopyRight By Aphcity
        2021年10月06日

*/

#include <stdio.h>
#include <stdlib.h>

/* 

        哈希表基本结构及操作

 */

typedef struct HashNode //哈希链表结点(同义词链结点)
{
    int key;        //散列元素值
    HashNode *next; //链表指针指向下一个同义词
} HashNode;

#define Maxsize 9        //哈希表关键字范围
typedef struct HashTable //哈希表
{
    HashNode *head; //哈希表关键字头指针(同义词链)
} HashTable[Maxsize];

//初始化哈希表
bool InitHashTable(HashTable &Table)
{
    for (int i = 0; i < Maxsize; i++)
        Table[i].head = NULL;

    return true;
}

//向哈希表内插入元素
bool InsertHashTable(HashTable &Table, int num)
{
    HashNode *NewNode;
    NewNode = (HashNode *)malloc(sizeof(HashNode)); //为新建立结点分配空间
    int index = num % Maxsize;                      //取得新插入元素的关键字

    //使用头插法,将新建立结点插入同义词链
    NewNode->next = Table[index].head;
    Table[index].head = NewNode;
    NewNode->key = num;

    return true;
}