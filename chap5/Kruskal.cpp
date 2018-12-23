#include <bits/stdc++.h>
#define Looper(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef struct
{
    int v1, v2;
    int weight;
} Edge;

bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

const int MAXEDGE = 11; //边数
const int MAXVEX = 7;   //顶点数
Edge edges[MAXEDGE];    //边的结构体
int ufs[MAXVEX];        //并查集

int Find(int root)
{
    while (ufs[root] >= 0)
        root = ufs[root];
    return root;
}

void Kruskal()
{
    int n, m; //选取的两个顶点的父亲,即记录这个顶点是否已经加入到生成树。
    sort(edges, edges + MAXEDGE, cmp);
    for (int i = 0; i < MAXVEX; i++)
        ufs[i] = -1;
    for (int i = 0; i < MAXEDGE; i++)
    {
        n = Find(edges[i].v1);
        m = Find(edges[i].v2);
        if (n != m) //该边未在生成树里
        {
            ufs[m] = n;
            printf("(%d -> %d), %d\n", edges[i].v1, edges[i].v2, edges[i].weight);
        }
    }
}

void SetEdge(int &cnt, int v1, int v2, int weight)
{
    edges[cnt].v1 = v1;
    edges[cnt].v2 = v2;
    edges[cnt].weight = weight;
    cnt++;
}

int main()
{
    int cnt = 0;
    SetEdge(cnt, 0, 1, 5);
    SetEdge(cnt, 0, 2, 11);
    SetEdge(cnt, 1, 3, 12);
    SetEdge(cnt, 1, 4, 2);
    SetEdge(cnt, 1, 5, 8);
    SetEdge(cnt, 2, 3, 24);
    SetEdge(cnt, 2, 6, 20);
    SetEdge(cnt, 3, 6, 18);
    SetEdge(cnt, 4, 5, 4);
    SetEdge(cnt, 4, 6, 15);
    SetEdge(cnt, 5, 6, 3);
    Kruskal();
    return 0;
}