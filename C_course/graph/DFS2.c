bool visited[MAXVEX]; // 判断是否访问过的数组

void DFS(Gadjlist G, int i)
{
    Enode *p = G->adjlist[i].firstedge;
    visited[i] = true;
    while (p)
    {
        int cnt = p->adjvex;
        if (!visited[cnt])
        {
            DFS(G, cnt);
        }
        p = p->next;
    }
}

void DFStraverse(Gadjlist G)
{
    int j = 0;
    while (j < G->numnodes)
    {
        visited[j] = false;
        j++;
    }

    for (int j = 0; j < G->numnodes; j++)
    {
        DFS(G, j);
    }
}