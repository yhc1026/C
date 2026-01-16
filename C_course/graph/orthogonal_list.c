// 十字链表，可以记录出度和入度，主要应用于有向图。

typedef struct Edgenode
{
    struct Edgenode *headlink; // 指向入弧的边节点
    struct Edgenode *taillink; // 指向出弧的边节点
    int tailvex;               // 记录这条边节点从哪个节点出
    int headvex;               // 记录这条边节点入到哪个节点
} Enode;

typedef struct vertexnode
{
    Enode *firstin;  // 记录入这个节点的第一条边
    Enode *firstout; // 记录出这个节点的第一条边
    int data;
} Vnode;
