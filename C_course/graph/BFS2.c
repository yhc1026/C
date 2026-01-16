// 使用队列和邻接表进行广度优先遍历
#include "D:\codeC\vscodeC\C_course\C-course\C_course\graph\graph2.1.c"
#include "D:\codeC\vscodeC\C_course\C-course\C_course\stack&queue\queue.c"

bool visited[MAXVEX]; // 判断是否访问过的数组

void BFS1(Gadjlist G)
{
    int i = 0, j = 0;
    Enode *p = NULL;
    Qmessage q;
    Qmessage *Q = &q;
    initqueue(Q);
    for (i = 0; i < G.numnodes; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            pushnode(Q, i);
        }
        while (!testempty(Q))
        {
            gethead(Q, i);
            popnode(Q);
            p = G.Alist[i]->firstedge;
            while (p)
            {
                if (!visited[p->adjvex])
                {
                    visited[p->adjvex] = true;
                    pushnode(Q, p->adjvex);
                }
                p = p->next;
            }
        }
    }
}
