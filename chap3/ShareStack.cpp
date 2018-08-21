#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 100;
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int top1, top2;
}ShareStack;

void initStack(ShareStack &S)
{
	S.top1 = -1;
	S.top2 = MAXSIZE;
}

bool isEmpty(ShareStack S, int stackNum)
{
	if (stackNum == 1)
		return S.top1 == -1;
	else
		return S.top2 == MAXSIZE;
}

bool isFull(ShareStack S)
{
	return S.top1 + 1 == S.top2;	//栈顶指针在数组中左右相邻即满
}

bool push(ShareStack &S, ElemType e, int stackNum)
{
	if (stackNum != 1 && stackNum != 2)
		return false;
	if (isFull(S))
		return false;
	if (stackNum == 1)
		S.data[++S.top1] = e;
	if (stackNum == 2)
		S.data[--S.top2] = e;
	return true;
}

bool pop(ShareStack &S, ElemType &e, int stackNum)
{
	if (stackNum != 1 && stackNum != 2)
		return false;
	if (isEmpty(S, stackNum))
		return false;
	if (stackNum == 1)
		e = S.data[S.top1--];
	if (stackNum == 2)
		e = S.data[S.top2++];
	return true;
}