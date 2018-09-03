#include <bits/stdc++.h>
#define Looper(i, n) for(int i = 0;i < n;i++)
using namespace std;

const int MaxVertexNum = 100;
typedef int VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vex[MaxVertexNum];
	EdgeType edge[MaxVertexNum][MaxVertexNum];
	int vexNum, arcNum;
}AMGraph;

void Init(AMGraph &G)
{
	G.vexNum = 7;
	Looper(i, 7)
	{
		G.vex[i] = i;
		Looper(j, 7)
		{
			if (i == j)
				G.edge[i][j] = 0;
			else
				G.edge[i][j] = INT32_MAX;
		}
	}
	G.edge[0][1] = G.edge[1][0] = 5;
	G.edge[0][2] = G.edge[2][0] = 11;
	G.edge[1][3] = G.edge[3][1] = 12;
	G.edge[3][2] = G.edge[2][3] = 24;
	G.edge[1][4] = G.edge[4][1] = 2;
	G.edge[5][1] = G.edge[1][5] = 8;
	G.edge[4][5] = G.edge[5][4] = 4;
	G.edge[4][6] = G.edge[6][4] = 15;
	G.edge[5][6] = G.edge[6][5] = 3;
	G.edge[3][6] = G.edge[6][3] = 18;
	G.edge[2][6] = G.edge[6][2] = 20;
}

void Prim(AMGraph G)
{
	int minValue = INT32_MAX;
	int adjvex[MaxVertexNum];
	int lowcost[MaxVertexNum];

}

int main()
{
	AMGraph g;
	Init(g);
	Looper(i, g.vexNum)
	{
		Looper(j, g.vexNum)
		{
			if (g.edge[i][j] != INT32_MAX)
				printf("%2d ", g.edge[i][j]);
			else
				printf("∞ ");
		}
		cout << endl;
	}
	return 0;
}