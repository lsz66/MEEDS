#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct SNode {
	ElemType data;
	SNode *next;
}SNode, *LinkStack;

void initStack(LinkStack &S)
{
	S = NULL;	//S是栈顶指针
}

bool push(LinkStack &S, ElemType e)
{
	SNode *p = new SNode;
	if (!p)
		return false;
	p->data = e;
	p->next = S;	//p->next指向当前栈顶
	S = p;			//栈顶改为p
	return true;
}

bool pop(LinkStack &S, ElemType &e)
{
	if (!S)
		return false;
	e = S->data;
	SNode *p = S;
	S = S->next;
	delete p;
	return true;
}