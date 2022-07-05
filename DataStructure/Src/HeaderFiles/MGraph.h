
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_VERTEX_NUM 100 // 矩阵最大容量
#define INF (~(0x1 << 31)) // 最大值(即0X7FFFFFFF)
#define isLetter(a) ((((a) >= 'a') && ((a) <= 'z')) || (((a) >= 'A') && ((a) <= 'Z')))
#define LENGTH(a) (sizeof(a) / sizeof(a[0]))

// 邻接矩阵
typedef struct _Graph
{
    char vexs[MAX_VERTEX_NUM];                // 顶点集合，顶点向量
    int vexnum;                               // 顶点数
    int edgnum;                               // 边数
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
} MGraph, *PGraph;

/*
 * 返回ch在arcs矩阵中的位置
 */
static int LocateVex(MGraph g, char ch)
{
    int i;
    for (i = 0; i < g.vexnum; i++)
        if (g.vexs[i] == ch)
            return i;
    return -1;
}

/*
 * 读取一个输入字符
 */
static char read_char()
{
    char ch;

    do
    {
        ch = getchar();
    } while (!isLetter(ch));

    return ch;
}

/*
 * 创建图(自己输入)
 */
MGraph *create_graph()
{
    char c1, c2;
    int v, e;
    int i, j, weight, p1, p2;
    MGraph *pG;

    // 输入"顶点数"和"边数"
    printf("input vertex number: ");
    scanf("%d", &v);
    printf("input edge number: ");
    scanf("%d", &e);
    if (v < 1 || e < 1 || (e > (v * (v - 1))))
    {
        printf("input error: invalid parameters!\n");
        return NULL;
    }

    if ((pG = (MGraph *)malloc(sizeof(MGraph))) == NULL)
        return NULL;
    memset(pG, 0, sizeof(MGraph));

    // 初始化"顶点数"和"边数"
    pG->vexnum = v;
    pG->arcnum = e;
    // 初始化"顶点"
    for (i = 0; i < pG->vexnum; i++)
    {
        printf("vertex(%d): ", i);
        pG->vexs[i] = read_char();
    }

    // 1. 初始化"边"的权值
    for (i = 0; i < pG->vexnum; i++)
    {
        for (j = 0; j < pG->vexnum; j++)
        {
            if (i == j)
                pG->arcs[i][j] = 0;
            else
                pG->arcs[i][j] = INF;
        }
    }
    // 2. 初始化"边"的权值: 根据用户的输入进行初始化
    for (i = 0; i < pG->arcnum; i++)
    {
        // 读取边的起始顶点，结束顶点，权值
        printf("edge(%d):", i);
        c1 = read_char();
        c2 = read_char();
        scanf("%d", &weight);

        p1 = LocateVex(*pG, c1);
        p2 = LocateVex(*pG, c2);
        if (p1 == -1 || p2 == -1)
        {
            printf("input error: invalid edge!\n");
            free(pG);
            return NULL;
        }

        pG->arcs[p1][p2] = weight;
        pG->arcs[p2][p1] = weight;
    }

    return pG;
}

/*
 * 创建图(用已提供的矩阵)
 */
MGraph *create_example_graph()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int matrix[][9] = {
        /*A*/ /*B*/ /*C*/ /*D*/ /*E*/ /*F*/ /*G*/
        /*A*/ {0, 12, INF, INF, INF, 16, 14},
        /*B*/ {12, 0, 10, INF, INF, 7, INF},
        /*C*/ {INF, 10, 0, 3, 5, 6, INF},
        /*D*/ {INF, INF, 3, 0, 4, INF, INF},
        /*E*/ {INF, INF, 5, 4, 0, 2, 8},
        /*F*/ {16, 7, 6, INF, 2, 0, 9},
        /*G*/ {14, INF, INF, INF, 8, 9, 0}};
    int vlen = LENGTH(vexs);
    int i, j;
    MGraph *pG;

    // 输入"顶点数"和"边数"
    if ((pG = (MGraph *)malloc(sizeof(MGraph))) == NULL)
        return NULL;
    memset(pG, 0, sizeof(MGraph));

    // 初始化"顶点数"
    pG->vexnum = vlen;
    // 初始化"顶点"
    for (i = 0; i < pG->vexnum; i++)
        pG->vexs[i] = vexs[i];

    // 初始化"边"
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            pG->arcs[i][j] = arcs[i][j];

    // 统计边的数目
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            if (i != j && pG->arcs[i][j] != INF)
                pG->arcnum++;
    pG->arcnum /= 2;

    return pG;
}

/*
 * 返回顶点v的第一个邻接顶点的索引，失败则返回-1
 */
static int first_vertex(MGraph G, int v)
{
    int i;

    if (v < 0 || v > (G.vexnum - 1))
        return -1;

    for (i = 0; i < G.vexnum; i++)
        if (G.arcs[v][i] != 0 && G.arcs[v][i] != INF)
            return i;

    return -1;
}

/*
 * 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
 */
static int next_vertix(MGraph G, int v, int w)
{
    int i;

    if (v < 0 || v > (G.vexnum - 1) || w < 0 || w > (G.vexnum - 1))
        return -1;

    for (i = w + 1; i < G.vexnum; i++)
        if (G.arcs[v][i] != 0 && G.arcs[v][i] != INF)
            return i;

    return -1;
}

/*
 * 深度优先搜索遍历图的递归实现
 */
static void DFS(MGraph G, int i, int *visited)
{
    int w;

    visited[i] = 1;
    printf("%c ", G.vexs[i]);
    // 遍历该顶点的所有邻接顶点。若是没有访问过，那么继续往下走
    for (w = first_vertex(G, i); w >= 0; w = next_vertix(G, i, w))
    {
        if (!visited[w])
            DFS(G, w, visited);
    }
}

/*
 * 深度优先搜索遍历图
 */
void DFSTraverse(MGraph G)
{
    int i;
    int visited[MAX_VERTEX_NUM]; // 顶点访问标记

    // 初始化所有顶点都没有被访问
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    printf("DFS: ");
    for (i = 0; i < G.vexnum; i++)
    {
        //printf("\n== LOOP(%d)\n", i);
        if (!visited[i])
            DFS(G, i, visited);
    }
    printf("\n");
}

/*
 * 广度优先搜索（类似于树的层次遍历）
 */
void BFS(MGraph G)
{
    int head = 0;
    int rear = 0;
    int queue[MAX_VERTEX_NUM];   // 辅组队列
    int visited[MAX_VERTEX_NUM]; // 顶点访问标记
    int i, j, k;

    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    printf("BFS: ");
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%c ", G.vexs[i]);
            queue[rear++] = i; // 入队列
        }
        while (head != rear)
        {
            j = queue[head++];                                             // 出队列
            for (k = first_vertex(G, j); k >= 0; k = next_vertix(G, j, k)) //k是为访问的邻接顶点
            {
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%c ", G.vexs[k]);
                    queue[rear++] = k;
                }
            }
        }
    }
    printf("\n");
}

/*
 * 打印矩阵队列图
 */
void print_graph(MGraph G)
{
    int i, j;

    printf("Martix Graph:\n");
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            printf("%10d ", G.arcs[i][j]);
        printf("\n");
    }
}

/*
 * prim最小生成树
 *
 * @param G 邻接矩阵图
 * @param start 从图中的第start个元素开始，生成最小树
 */
void prim(MGraph G, int start)
{
    int min, i, j, k, m, n, sum;
    int index = 0;               // prim最小树的索引，即prims数组的索引
    char prims[MAX_VERTEX_NUM];  // prim最小树的结果数组
    int weights[MAX_VERTEX_NUM]; // 顶点间边的权值

    // prim最小生成树中第一个数是"图中第start个顶点"，因为是从start开始的。
    prims[index++] = G.vexs[start];

    // 初始化"顶点的权值数组"，
    // 将每个顶点的权值初始化为"第start个顶点"到"该顶点"的权值。
    for (i = 0; i < G.vexnum; i++)
        weights[i] = G.arcs[start][i];
    // 将第start个顶点的权值初始化为0。
    // 可以理解为"第start个顶点到它自身的距离为0"。
    weights[start] = 0;

    for (i = 0; i < G.vexnum; i++)
    {
        // 由于从start开始的，因此不需要再对第start个顶点进行处理。
        if (start == i)
            continue;

        j = 0;
        k = 0;
        min = INF;
        // 在未被加入到最小生成树的顶点中，找出权值最小的顶点。
        while (j < G.vexnum)
        {
            // 若weights[j]=0，意味着"第j个节点已经被排序过"(或者说已经加入了最小生成树中)。
            if (weights[j] != 0 && weights[j] < min)
            {
                min = weights[j];
                k = j;
            }
            j++;
        }

        // 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点。
        // 将第k个顶点加入到最小生成树的结果数组中
        prims[index++] = G.vexs[k];
        // 将"第k个顶点的权值"标记为0，意味着第k个顶点已经排序过了(或者说已经加入了最小树结果中)。
        weights[k] = 0;
        // 当第k个顶点被加入到最小生成树的结果数组中之后，更新其它顶点的权值。
        for (j = 0; j < G.vexnum; j++)
        {
            // 当第j个节点没有被处理，并且需要更新时才被更新。
            if (weights[j] != 0 && G.arcs[k][j] < weights[j])
                weights[j] = G.arcs[k][j];
        }
    }

    // 计算最小生成树的权值
    sum = 0;
    for (i = 1; i < index; i++)
    {
        min = INF;
        // 获取prims[i]在G中的位置
        n = LocateVex(G, prims[i]);
        // 在vexs[0...i]中，找出到j的权值最小的顶点。
        for (j = 0; j < i; j++)
        {
            m = LocateVex(G, prims[j]);
            if (G.arcs[m][n] < min)
                min = G.arcs[m][n];
        }
        sum += min;
    }
    // 打印最小生成树
    printf("PRIM(%c)=%d: ", G.vexs[start], sum);
    for (i = 0; i < index; i++)
        printf("%c ", prims[i]);
    printf("\n");
}
