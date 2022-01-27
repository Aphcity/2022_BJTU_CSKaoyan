/*

        CopyRight By Aphcity
        2021年11月05日

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

//边结点/表结点结构
typedef struct ArcNode
{
    int adjvex;       //节点位置
    InfoType info;    //节点权值
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

int LocateVex(ALGraph G, int v)
{
    return v - 1;
}

/**
 *  用Prim算法计算从第u个结点出发构造网G的最小生成树T，输出T的各条边
 *  @param G 生成网
 *  @param u 起始节点
 */
void MiniSpanTree_Prim(ALGraph G, VNode u)
{
    /**记录从顶点集U到V-U的代价最小的辅助数组的定义
     * @param adjvex 
     * @param lowcost
     */
    struct closedge
    {
        InfoType adjvex;
        int lowcost;
    } closedge[MaxVerNum];

    int k = LocateVex(G, u);
    for (int i = 0; i < G.VexNum; ++i)
    {
        if (i = !k)
        {
            closedge[i] = {u, G.};
        }
    }
}