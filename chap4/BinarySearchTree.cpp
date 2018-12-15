#include <bits/stdc++.h>
#define Looper(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef int KeyType;
typedef struct BSTNode
{
	KeyType data;
	BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTNode *RSearch(BSTree T, KeyType key)
{
	if (key == T->data || (!T)) //查找成功返回结点，查无此点返回NULL
		return T;
	else if (key < T->data)
		return RSearch(T->lchild, key);
	else
		return RSearch(T->rchild, key);
}

BSTNode *Search(BSTree T, KeyType key)
{
	BSTree p = T;
	while (p && key != p->data) //查找成功返回结点，查无此点返回NULL
	{
		if (key < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return p;
}

bool InsertBST(BSTree &T, KeyType e)
{
	if (!T) //找到空位，即将插入
	{
		T = new BSTNode;
		T->data = e;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if (e == T->data) //找到了一个key值相同的结点
		return false;
	else if (e < T->data)
		return InsertBST(T->lchild, e);
	else
		return InsertBST(T->rchild, e);
}

void CreateBST(BSTree &T, vector<KeyType> v)
{
	T = NULL;
	Looper(i, v.size())
		InsertBST(T, v[i]);
}

bool DeleteBST(BSTree &T, KeyType key)
{
	BSTree p = T; //p:工作指针
	while (p)
	{
		if (p->data == key)
			break; //查找成功
		if (key < p->data)
			p = p->lchild; //当前结点比要找节点小，往左找
		else
			p = p->rchild;
	}
	if (!p)
		return false; //没有这个结点，删除失败
	//查找成功，开始删除
	if (!p->lchild && !p->rchild)
	{
		//叶子节点，直接删
		delete p;
		return true;
	}
	BSTree q = p, s;
	if (!p->lchild) //没有左儿子
		p = p->rchild;
	else if (!p->rchild)
		p = p->lchild;
	else
	{
		//左右儿子都有，找前驱
		s = p->lchild;	//被删结点的左儿子
		while (s->rchild) //找到其最右
		{
			q = s; //最右节点他爸
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		delete s;
		return true;
	}
}

void InOrder(BSTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		cout << T->data << ' ';
		InOrder(T->rchild);
	}
}

int main()
{
	vector<KeyType> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(4);
	BSTree t;
	CreateBST(t, v);
	InOrder(t);
	cout << endl;
	return 0;
}