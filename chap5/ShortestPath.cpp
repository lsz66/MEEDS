#include <bits/stdc++.h>
#define Looper(i, n) for(int i = 0; i < n; i++)
using namespace std;

const int MaxVertexNum = 100;
typedef int VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vex[MaxVertexNum];
	EdgeType edge[MaxVertexNum][MaxVertexNum];
	int vexNum, arcNum;
}AMGraph;

void Floyd(AMGraph G, int *path[])
{
	int A[MaxVertexNum][MaxVertexNum];
	Looper(i, G.vexNum)
	{
		Looper(j, G.vexNum)
		{
			A[i][j] = G.edge[i][j];
			path[i][j] = -1;
		}
	}
	Looper(k, G.vexNum)
	{
		Looper(i, G.vexNum)
		{
			Looper(j, G.vexNum)
			{
				if (A[i][j] > A[i][k] + A[k][j])	//直接距离比绕行距离长
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}