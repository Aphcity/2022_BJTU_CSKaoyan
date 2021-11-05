/*

        CopyRight By Aphcity
        2021年11月04日

*/

#include <stdio.h>
#include <stdlib.h>

/* 

        图的邻接表表示法基本存储结构

 */

#define InfoType int
#define MaxVerNum 10

//定义枚举类型的变量，表示图的种类
typedef enum GraphKind
{
    DG, //有向图
    UDG //无向图
} GraphKind;

//边结点/表结点结构
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
} ALGraph;

bool visit(ALGraph G, int v)
{
    printf("%d\n", G.Vertices[v].data);
    return true;
}

int FirstNeighbor(ALGraph G, int v)
{
    return G.Vertices[v].firstArc->info;
}

int NextNeighbor(ALGraph G, int v, int w)
{
    return G.Vertices[v].firstArc->info;
}

//BFS遍历需要借助辅助队列结构
typedef struct SeqQueue
{
    int data[MaxVerNum];
    int front;
    int rear;
} SeqQueue;

bool InitSeqQueue(SeqQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    return true;
}

bool IsSeqQueueEmpty(SeqQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    return false;
}

bool InsertSeqQueue(SeqQueue &Q, int num)
{
    if (Q.front == (Q.rear + 1) % MaxVerNum)
        return false;
    Q.data[Q.rear++] = num;
    return true;
}

bool DeleteSeqQueue(SeqQueue &Q, int &num)
{
    if (IsSeqQueueEmpty(Q))
        return false;
    num = Q.data[Q.front++];
    return true;
}

//遍历使用全局变量
bool visited[MaxVerNum];
SeqQueue Q;

//从第v个结点出发，深度优先遍历DFS
void DFS(ALGraph G, int v)
{
    visit(G, v);
    visited[v] = true;
    for (int i = FirstNeighbor(G, v); i >= 0; i = NextNeighbor(G, v, i))
        if (!visited[i])
            DFS(G, i);
}

//DFS遍历入口，防止非连通图无法完全遍历
void DFSTraverse(ALGraph G)
{
    for (int i = 0; i < G.VexNum; ++i)
        visited[i] = false;

    for (int i = 0; i < G.VexNum; ++i)
        if (!visited[i])
            DFS(G, i);
}

//从第v个结点出发，广度优先遍历BFS
void BFSTraverse(ALGraph G)
{
    for (int i = 0; i < G.VexNum; ++i)
        visited[i] = false;
    InitSeqQueue(Q);
    for (int i = 0, u = 0; i < G.VexNum; ++i)
        if (!visited[i])
        {
            visited[i] = true;
            visit(G, i);
            InsertSeqQueue(Q, i);
            while (!IsSeqQueueEmpty(Q))
            {
                DeleteSeqQueue(Q, u);
                for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
                    if (!visited[w])
                    {
                        visited[w] = true;
                        visit(G, w);
                        InsertSeqQueue(Q, w);
                    }
            }
        }
}

int main()
{
    return 0;
}