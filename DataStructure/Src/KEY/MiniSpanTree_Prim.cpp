/*

        CopyRight By Aphcity
        2021年11月05日

*/

#include <MGraph.h>

#define VertexType char

/**
 *  用Prim算法计算从第u个结点出发构造网G的最小生成树T，输出T的各条边
 *  @param G 生成网
 *  @param u 起始节点
 */
void MiniSpanTree_Prim(MGraph G, VertexType u)
{
    /**记录从顶点集U到V-U的代价最小的辅助数组的定义
     * @param adjvex 
     * @param lowcost
     */
    struct closedge
    {
        VertexType adjvex;
        int lowcost;
    } closedge[MaxVerNum];

    int k = LocateVex(G, u);
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (i = !k)
            closedge[i] = {u, G.arcs[k][j]};
        closedge[k].lowcost = 0;
    }
    for (int i = 0; i < G.vexnum; ++i)
    {
        // k = m;
    }
}

int main()
{
    return 0;
}