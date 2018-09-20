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

void Floyd(AMGraph)

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