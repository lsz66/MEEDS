#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 5;
typedef int ElemType;
typedef struct {
	ElemType *data;
	int front, rear;
}SqQueue;

bool initQueue(SqQueue &Q)
{
	Q.data = new ElemType[MAXSIZE];
	if (!Q.data)
		return false;
	Q.front = Q.rear = 0;
	return true;
}

bool isEmpty(SqQueue Q)
{
	return Q.front == Q.rear;
}

bool isFull(SqQueue Q)
{
	//队尾指针+1取模后如果是队头就满
	return (Q.rear + 1) % MAXSIZE == Q.front;
}

int queueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

bool enQueue(SqQueue &Q, ElemType e)
{
	if (isFull(Q))
		return false;
	Q.data[Q.rear] = e;	//入队尾
	Q.rear = (Q.rear) + 1 % MAXSIZE;	//队尾下标+1
	return true;
}

bool deQueue(SqQueue &Q, ElemType &e)
{
	if (isEmpty(Q))
		return false;
	e = Q.data[Q.front];	//取队首
	Q.front = (Q.front + 1) % MAXSIZE;	//队首下标+1
	return true;
}

int main()
{
	SqQueue q;
	initQueue(q);
	cout << isEmpty(q) << endl;
	for (int i = 1; i <= 5; i++)
		enQueue(q, i);
	cout << isFull(q) << endl;
	cout << queueLength(q) << endl;
	int e;
	deQueue(q, e);
	deQueue(q, e);
	cout << e << endl;
	return 0;
}