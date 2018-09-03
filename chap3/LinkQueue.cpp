#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct  {
	ElemType data;
	LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front, *rear;
}LinkQueue;

bool initQueue(LinkQueue &Q)
{
	Q.front = Q.rear = new LinkNode;	//初始化，建立头结点。
	if (!Q.front)
		return false;
	Q.front->next = NULL;
	return true;
}

bool isEmpty(LinkQueue Q)
{
	return Q.front == Q.rear;
}

void enQueue(LinkQueue &Q, ElemType e)
{
	LinkNode *s = new LinkNode;
	s->data = e;
	s->next = NULL;	//因为是插到队尾，所以下一个肯定为空。
	Q.rear->next = s;	//原队尾结点为新插入结点的后继
	Q.rear = s;		//新的队尾
}

bool deQueue(LinkQueue &Q, ElemType &e)
{
	if (isEmpty(Q))
		return false;
	LinkNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;	//如果出队的是最后一个元素，就要将队尾指针指向链队头指针
	delete p;
	return true;
}