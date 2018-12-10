#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void Visit(BiTree T)
{
	cout << T->data << endl;
}

void CreateBiTree(BiTree &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//遍历的递归算法
void PreOrder(BiTree T)
{
	if (T)
	{
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T)
{
	if (T)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		Visit(T);
	}
}

//遍历的非递归算法
void PreOrderTraverse(BiTree T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p || !s.empty())
	{
		if (p) //将左子结点入栈
		{
			Visit(p);	  //访问结点
			s.push(p);	 //入栈保存
			p = p->lchild; //访问子结点
		}
		else //遇到没有左子结点的结点
		{
			p = s.top();
			s.pop();	   //最近访问的结点出栈
			p = p->rchild; //开始访问其右子结点
		}
	}
}

void InOrderTraverse(BiTree T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p || !s.empty())
	{
		if (p) //将左子结点入栈
		{
			s.push(p);	 //入栈保存
			p = p->lchild; //访问子结点
		}
		else //遇到没有左子结点的结点
		{
			p = s.top();
			s.pop();	   //最近访问的结点出栈
			Visit(p);	  //访问结点
			p = p->rchild; //开始访问其右子结点
		}
	}
}

void PostOrderTraverse(BiTree T)
{
	stack<BiTree> s;
	BiTree p = T, r = NULL;
	while (p || !s.empty())
	{
		if (p) //将左子结点入栈
		{
			s.push(p);	 //入栈保存
			p = p->lchild; //访问子结点
		}
		else //遇到没有左子结点的结点
		{
			p = s.top();
			if (p->rchild && p->rchild != r) //右子树还没访问
				p = p->rchild;				 //访问右子树
			else							 //右子树已访问
			{
				s.pop();
				cout << p->data << ' ';
				r = p;
				p = NULL;
			}
		}
	}
}

void LevelOrder(BiTree T)
{
	if (!T)
		return;
	queue<BiTree> q;
	BiTree p = T;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		//记得判断左右子树是不是空的
		if (p->lchild)
			q.push(p->lchild);
		if (p->rchild)
			q.push(p->rchild);
		cout << p->data << ' ';
	}
	cout << endl;
}

int main()
{
	BiTree t;
	CreateBiTree(t);
	LevelOrder(t);
	return 0;
}