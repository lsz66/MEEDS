#include <bits/stdc++.h>
#define Looper(i, n) for(int i = 0;i < n;i++)
using namespace std;

const int MaxVertexNum = 100;
typedef int VertexType;
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

void InitGraph(ALGraph &G)	//拓扑排序.png
{
	G.vexNum = 7;
	Looper(i, 7)
		G.vertices[i].data = i + 1;
	G.vertices[0].first = new ArcNode(1, new ArcNode(2, new ArcNode(3, NULL)));
	G.vertices[1].first = new ArcNode(2, new ArcNode(4, NULL));
	G.vertices[2].first = new ArcNode(4, NULL);
	G.vertices[3].first = new ArcNode(5, NULL);
	G.vertices[4].first = new ArcNode(6, NULL);
	G.vertices[5].first = new ArcNode(2, new ArcNode(6, NULL));
	G.vertices[6].first = NULL;
}

void FindIndegree(ALGraph G, int indegree[])	//找所有顶点的入度
{
	Looper(i, G.vexNum)
	{
		ArcNode *p = G.vertices[i].first;
		while (p)
		{
			indegree[p->adjvex]++;
			p = p->next;
		}
	}
}

bool TopologicalSort(ALGraph G)
{
	int indegree[7];
	memset(indegree, 0, sizeof(indegree));
	FindIndegree(G, indegree);
	//初始化完成，开始拓扑排序算法
	stack<int> s;	//入度为0的顶点的栈
	Looper(i, G.vexNum)
		if (indegree[i] == 0)	//储存入度为0的点
			s.push(i);
	int cnt = 0;
	while (!s.empty())
	{
		int i = s.top();
		s.pop();	//栈顶元素出栈，是一个入度为0的顶点
		cout << G.vertices[i].data << ' ';	//输出顶点
		cnt++;
		for (ArcNode *p = G.vertices[i].first; p; p = p->next)
		{
			//取此顶点的所有弧指向的顶点
			int v = p->adjvex;
			if (!(--indegree[v]))	//取一个顶点就把这条弧删掉
				s.push(v);	//如果该顶点入度为0则入栈
		}
	}
	cout << endl;
	if (cnt < G.vexNum)
		return false;
	else
		return true;
}

int main()
{
	ALGraph g;
	InitGraph(g);
	TopologicalSort(g);
	return 0;
}