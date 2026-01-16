// 使用队列和邻接矩阵进行广度优先遍历

#include "D:\codeC\vscodeC\C_course\C-course\C_course\graph\graph1.c"
#include "D:\codeC\vscodeC\C_course\C-course\C_course\stack&queue\queue.c"

#include <stdbool.h>
bool visited[MAXVEX]; // 判断是否访问过的数组

void BFS1(Mgraph G)
{
    int i = 0, j = 0;
    Qmessage q;
    Qmessage *Q = &q;
    initqueue(Q);
    for (i = 0; i < G.numnodes; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            pushnode(Q, i);
            while (!testempty(Q))
            {
                gethead(Q, i);
                popnode(Q);
                for (j = 0; j < G.numnodes; j++)
                {
                    if (G.arc[i][j] != 0 && !visited[j])
                    {
                        visited[j] = true;
                        pushnode(Q, j);
                    }
                }
            }
        }
    }
}
