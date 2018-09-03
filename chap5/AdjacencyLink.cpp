#include <bits/stdc++.h>
#define Looper(i, n) for(int i = 0;i < n;i++)
using namespace std;

const int MaxVertexNum = 100;
typedef char VertexType;
typedef int EdgeType;
typedef struct ArcNode {	//边表结点（链表）
	int adjvex;		//该弧指向下一个结点的位置
	ArcNode *next;	//指向下一条弧指针
	ArcNode(int a, ArcNode* n) :adjvex(a), next(n) {};
}ArcNode;
typedef struct VNode {	//顶点结点
	VertexType data;
	ArcNode *first;
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;
	int vexNum, arcNum;
}ALGraph;

bool visited[MaxVertexNum];
//从顶点表下标v开始广度遍历图
void BFS(ALGraph G, int v)
{
	ArcNode *p;
	queue<int> q;
	cout << G.vertices[v].data << ' ';	//访问顶点v，输出其数据域的值
	visited[v] = true;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();	//获取队头的值
		q.pop();		//顶点出队
		p = G.vertices[v].first;	//工作指针指向边表头指针，也就是下一个邻居结点
		while (p)	//遍历边表（链表）
		{
			if (!visited[p->adjvex])	//该顶点未被访问
			{
				cout << G.vertices[p->adjvex].data << ' ';
				visited[p->adjvex] = true;
				q.push(p->adjvex);
			}
			p = p->next;
		}
	}
}

void BFSTraverse(ALGraph G)
{
	Looper(i, G.vexNum)
		visited[i] = false;
	Looper(i, G.vexNum)
		if (!visited[i])
			BFS(G, i);	//非连通图的下一个连通分量
}

//单源最短路径
void MinDistance(ALGraph G, int u)
{
	int dis[MaxVertexNum];
	Looper(i, G.vexNum)
	{
		visited[i] = false;
		dis[i] = -1;
	}
	visited[u] = true;
	dis[u] = 0;
	ArcNode *p;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		u = q.front();	//获取队头的值
		q.pop();		//顶点出队
		p = G.vertices[u].first;	//工作指针指向边表头指针，也就是下一个邻居结点
		while (p)	//遍历边表（链表）
		{
			if (!visited[p->adjvex])	//该顶点未被访问
			{
				visited[p->adjvex] = true;
				dis[p->adjvex] = dis[u] + 1;
				q.push(p->adjvex);
			}
			p = p->next;
		}
	}
	Looper(i, G.vexNum)
		cout << dis[i] << ' ';
	cout << endl;
}

void DFS(ALGraph G, int v)
{
	ArcNode *p;
	cout << G.vertices[v].data << ' ';
	visited[v] = true;
	p = G.vertices[v].first;
	while (p)	//遍历边表（链表）
	{
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}

void DFSTraverse(ALGraph G)
{
	Looper(i, G.vexNum)
		visited[i] = false;
	Looper(i, G.vexNum)
		if (!visited[i])
			DFS(G, i);
}

int main()
{
	ALGraph g;
	g.vertices[0].data = 'A';
	g.vertices[0].first = new ArcNode(1, new ArcNode(2, new ArcNode(3, NULL)));
	g.vertices[1].data = 'B';
	g.vertices[1].first = new ArcNode(0, new ArcNode(2, new ArcNode(4, NULL)));
	g.vertices[2].data = 'C';
	g.vertices[2].first = new ArcNode(0, new ArcNode(1, new ArcNode(3, NULL)));
	g.vertices[3].data = 'D';
	g.vertices[3].first = new ArcNode(0, new ArcNode(2, NULL));
	g.vertices[4].data = 'E';
	g.vertices[4].first = new ArcNode(1, NULL);
	g.vexNum = 5;
	BFSTraverse(g);
	cout << endl;
	DFSTraverse(g);
	cout << endl;
	return 0;
}