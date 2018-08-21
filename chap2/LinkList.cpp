#include <bits/stdc++.h>
using namespace std;


//LinkList
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode, *LinkList;

//初始化
bool initList(LinkList &L)
{
	L = new LNode;
	if (!L)
		return false;
	L->next = NULL;
	return true;
}

//头插法创建链表，插入O(1)，总时间O(n)
void headInsertCreate(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	LNode *s;
	int x;
	while (cin >> x)
	{
		s = new LNode;
		s->data = x;		//结点赋值
		s->next = L->next;	//插入到链表头
		L->next = s;		
	}
}

//尾插法创建链表，插入O(1)，总时间O(n)
void tailInsertCreate(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	LNode *r = L;		//尾指针，当前为空表所以指向头指针
	int x;
	while (cin >> x)
	{
		LNode *s = new LNode;	//临时结点
		s->data = x;			//结点赋值
		r->next = s;			//尾指针的下一个结点指向临时结点，即插入
		r = s;					//临时结点为尾结点
	}
	r->next = NULL;	//漏掉这个不行
}

//按位置查找节点，返回结点，O(n)
LNode* getElem(LinkList L, int pos)
{
	LNode *p = L->next;
	if (pos < 0)
		return NULL;	//位置不合法
	if (pos == 0)
		return L;		//0即头结点
	int i = 1;			//从第一个结点即头结点之后找
	while (p&&i < pos)	//i==pos即结束，就是要找的那个结点
	{
		p = p->next;
		i++;
	}
	return p;
}

//按值查找，返回值，O(n)
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

/**
 * 插入节点
 * 链表插入操作为O(1)，但需要找到前驱节点
 * 而查找前驱节点为O(n)
 * 所以该函数时间复杂度为O(n)
 */
bool listInsert(LinkList &L, int i, ElemType e)
{
	LNode *p = getElem(L, pos - 1);
	if (!p)
		return false;
	/*严蔚敏版本，跟上面语句同理，找到要插入的结点的前驱
		LinkList p = L->next;
		int j = 1;
		while (p && j < i - 1)
		{
			p = p->next;	//定位到第i-1个节点
			j++;
		}
		if (!p || j > i - 1)	//i非法
			return false;
	*/
	LNode* s = new LNode;
	s->next = p->next;
	s->data = e;
	p->next = s;
	return true;
}

//删除节点
bool listDelete(LinkList &L, int pos)
{
	LNode *p = getElem(L, pos - 1);
	if (!p)
		return false;
	/*
		LinkList p = L->next;
		int j = 1;
		while (p && j < i - 1)
		{
			p = p->next;	//定位到第i-1个节点
			j++;
		}
		if (!(p->next) || j > i - 1)	//i非法
			return false;
	*/
	LNode *s = p->next;
	if (!s)
		return false;
	p->next = s -> next;
	delete s;
	return true;
}

/**
 * 从上面可以看出，不管是插入节点还是删除节点，
 * 都需要找到插入（删除）位置节点的前驱节点。
 */

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

void printList(LinkList L)
{
	int len = 0;
	LinkList p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
		len++;
	}
	cout << endl << "表长为：" << len << endl;;
}

int main()
{
	return 0;
}