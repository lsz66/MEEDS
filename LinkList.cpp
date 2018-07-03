#include <bits/stdc++.h>
using namespace std;


//LinkList
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode, *LinkList;

bool initList(LinkList &L)
{
	L = new LNode;
	if (!L)
		return false;
	L->next = NULL;
	return true;
}

bool getElem(LinkList L, int i, ElemType &e)
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i)	//定位到第i个节点
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)	//i非法
		return false;
	e = p->data;
	return true;
}

bool listInsert(LinkList &L, int i, ElemType e)
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i - 1)
	{
		p = p->next;	//定位到第i-1个节点
		j++;
	}
	if (!p || j > i - 1)	//i非法
		return false;
	LNode* s = new LNode;
	s->next = p->next;
	s->data = e;
	p->next = s;
	return true;
}

bool listDelete(LinkList &L, int i)
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i - 1)
	{
		p = p->next;	//定位到第i-1个节点
		j++;
	}
	if (!(p->next) || j > i - 1)	//i非法
		return false;
	LNode *s = p->next;
	p->next = s -> next;
	delete s;
	return true;
}

void clearList(LinkList &L)
{
	LinkList p = L;
	while (L->next)
	{
		p = L->next;
		L->next = p->next;
		delete p;
	}
}

bool createList(LinkList &L)
{

}

void printList(LinkList L)
{
	LinkList p = L;
	while (!p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	cout << endl;
}

int main()
{
	return 0;
}