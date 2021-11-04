/*

        CopyRight By Aphcity
        2021年10月30日

*/

#include <stdio.h>
#include <stdlib.h>

/* 

        图的邻接表表示法基本存储结构

 */

#define InfoType int;
#define MaxVerNum 10;
#define DG 1;
#define UDG 0;

//定义枚举类型的变量，表示图的种类
typedef enum GraphKind
{
    DG, //有向图
    UDG //无向图
};

//表结点结构
typedef struct ArcNode
{
    int adjvex;       //节点边长
    InfoType info;    //节点数据
    ArcNode *nextarc; //下一个邻接点指针
} ArcNode;

//头结点结构
typedef struct VNode
{
    InfoType data;     //关键字数据
    ArcNode *firstArc; //第一个邻接点的指针
} VNode, VList[MaxVerNum];

//邻接表表示的图
typedef struct ALGraph
{
    VList Vertices; //顶点向量
    int ArcNum;     //图的弧数
    int VexNum;     //顶点数
    GraphKind Kind; //图的类型
};
