#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;
typedef struct ThreadNode {
	ElemType data;
	ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;

void InThreading(ThreadTree &p, ThreadTree &pre)
{	//pre初始为空，因为找到最左结点他是没有前驱的
	if (p)
	{
		InThreading(p->lchild, pre);
		if (!p->lchild)	//p没有左儿子
		{
			p->ltag = 1;
			p->lchild = pre;
		}
		else
			p->ltag = 0;
		if (!p->rchild && !pre->rchild)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		else
			p->rtag = 0;
		pre = p;
		InThreading(p->rchild, pre);
	}
}

void InOrderTraverse(ThreadTree T)
{
	ThreadTree p = T;
	while (p)
	{
		while (p->ltag == 0)
			p = p->lchild;	//找到最左的结点
		cout << p->data;
		while (p->rtag&&p->rchild)	//如果右孩子是孩子不是后继的话
		{
			p = p->rchild;
			cout << p->data;
		}
		p = p->rchild;	//指向右孩子，其实也是后继
	}
}

ThreadNode* FirstNode(ThreadTree p)
{	//找最左的儿子
	while (!p->ltag)
		p = p->lchild;
	return p;
}

ThreadNode* NextNode(ThreadTree p)
{
	if (!p->rtag)	//找到该右子树最左的儿子
		return FirstNode(p->rchild);
	else
		return p->rchild;
}

void InOrder(ThreadTree T)
{
	for (auto p = FirstNode(T); p; p = NextNode(p))
		cout << p->data;
	cout << endl;
}

int main()
{
	auto t = new ThreadNode;
	cout << t->ltag << endl;
	return 0;
}