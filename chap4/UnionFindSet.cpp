#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
int UFSets[SIZE];	//并查集数组

void Init(int S[])
{
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;	//此时都是孤儿
}

int Find(int S[], int x)
{
	while (S[x] >= 0)
		x = S[x];	//一直找它的根
	return x;
}

void Union(int S[], int root1, int root2)
{
	S[root2] = root1;
}