// 图的存储结构1：邻接矩阵
// 本质是一个二维数组
// 假设图有n个顶点，则二维矩阵就是n*n
// 假设Va到Vb有一条有向弧，则arr[a][b]=1

// 邻接矩阵实现图的创建
typedef char vertype;  // 顶点数据类型
typedef int edgetype;  // 边的数据类型
#define MAXVEX 100     // 最大顶点数量,也就是邻接矩阵的大小
#define INFINITY 99999 // 对于有向图而言,如果两点之间不可达,就用99999代表正无穷,表示不可达
typedef struct
{
    vertype vexs[MAXVEX];         // 顶点表
    edgetype arc[MAXVEX][MAXVEX]; // 边表(邻接矩阵)
    int numnodes, numedges;       // 图中当前的顶点数量和边的数量
} Mgraph;

// 初始化图
void creategraph(Mgraph *G)
{
    int flag = 0; // 用户决定是否为有向图
    printf("有向图输入1,无向图输入0");
    scanf("%d", flag);

    scanf("%d", &G->numnodes);              // 获取节点个数
    for (int i = 0; i < (G->numnodes); i++) // 初始化vexs数组,便于将来管理图节点
    {
        scanf("%d", &G->vexs[i]);
    }

    for (int a = 0; a < G->numnodes; a++) // 初始化邻接矩阵,全部设置为无穷
    {
        for (int b = 0; b < G->numnodes; b++)
        {
            G->vexs[i][j] = INFINITY;
        }
    }

    scanf(&G->numedges); // 获取边数量
    int m = 0, n = 0, w = 0;
    for (int k = 0; k < G->numedges; k++) // 逐个获取每个边的信息
    {
        printf("输入边的下标和权(第一行第一列为0,0)");
        scanf("%d,%d,%d", &m, &n, &w);
        G->arc[m][n] = w;
        if (flag == 0) // 如果为无向图,邻接矩阵为对称矩阵
        {
            G->arc[n][m] = G->arc[m][n];
        }
    }
}