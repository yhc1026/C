// 邻接多重表，解决了邻接表和十字链表；增删边需要二重操作的问题
// 设i<j,对于任何一个节点Vj，如果Vi已经存储过与之相连的边，则Vj不再记录这条边

typedef struct edgenode
{
    int ivex;               // 表示这条边依附于i顶点
    int jvex;               // 表示这条边依附于j顶点
    struct edgenode *ilink; // 指向依附于i的边，即指向ivex为i的边
    struct edgenode *jlink; // 指向依附于j的边，即指向jvex为j的边
    int info;               // 权重（网专用）
    bool flag;              // 标记这条边是否被搜索过
}

typedef struct vertexnode
{
    Enode *firstedge; // 指向第一个节点，并改变flag数值
    int data;
} Vnode;