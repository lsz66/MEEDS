#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct DNode {
	ElemType data;
	DNode *prior, *next;
}DNode, *DLinkList;

bool initList(DLinkList &L)
{
	L = new DNode;
	if (!L)
		return false;
	L->next = NULL;
	return true;
}

DNode* getElem(DLinkList L, int pos)
{
	if (pos < 0)
		return NULL;
	if (pos == 0)
		return L;
	DNode *p = L->next;
	int i = 1;
	while (p&&i < pos)
		p = p->next;
	return p;
}

bool insert(DLinkList &L, int pos, ElemType e)
{
	DNode *p = getElem(L, pos - 1);
	if (!p)
		return false;
	DNode *s = new DNode;
	s->next = p->next;
	s->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool remove(DLinkList &L, int pos, ElemType &e)
{
	DNode *p = getElem(L, pos - 1);
	if (!p)
		return false;
	DNode *q = p->next;
	p->next = q->next;
	q->next->prior = p;
	delete q;
	return true;
}