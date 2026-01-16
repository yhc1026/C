// 邻接表

#include "D:\codeC\vscodeC\C_course\C-course\C_course\graph\graph1.c"
typedef struct edgenode
{
    int adjvex;
    int weight;
    struct edgenode *next;
} Enode;

typedef struct vertexnode
{
    char info;
    Enode *firstedge;
} Vnode, adjlist[MAXVEX];

typedef struct
{
    adjlist Alist; // 创建一个数组
    int numedges, numnodes;
} Gadjlist;

void createGadjlist(Gadjlist *G)
{
    int a = 0, b = 0;
    printf("输入顶点和边的数量");
    scanf("%d, %d", G->numnodes, G->numedges);
    for (int i = 0; i < G->numnodes; i++)
    {
        scanf("%d", G->Alist[i]);
        G->Alist[i].firstedge = NULL;
    }
    Enode *e = NULL;
    for (int k = 0; k < G->numedges; k++)
    {
        printf("输入边的序号");
        scanf("%d, %d", &a, &b);

        e = (Enode *)malloc(sizeof(Enode));
        e->adjvex = j;                   // 表示该边指针指向j节点
        e->next = G->Alist[i].firstedge; // 为头插法，如果这是第一轮操作，见第31行，firstedge为空，那么此处无意义；若不是第一轮操作，firstedge另有其人，则将e头插到原firstedge前面，结合下一行操作，成为新的firstedge
        G->Alist[i].firstedge = e;       // e所代表的边指针成为新的firstedge

        e = (Enode *)malloc(sizeof(Enode)); // 以下四行代码为边的双向化操作，与39-42本质相同。 对象为j节点，同样的道理把新e边节点作为j的firstedge，使得两点间形成双向边
        e->adjvex = i;
        e->next = G->Alist[j].firstedge;
        G->Alist[j].firstedge = e;
    }
}
