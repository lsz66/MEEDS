#include <bits/stdc++.h>
using namespace std;

//SqList
const int MAXSIZE = 100;
typedef int ElemType;
typedef struct {
	ElemType * elem;
	int size;
}SqList;

bool InitList(SqList &L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		return false;
	L.size = 0;
	return true;
}

bool GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.size)
		return false;
	e = L.elem[i - 1];
	return true;
}

int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.size; i++)
		if (L.elem[i] == e)
			return i + 1;
	return false;
}

bool ListInsert(SqList &L, int i, ElemType e)
{
	if (i<1 || i>L.size + 1)
		return false;
	for (int j = L.size; j >= i; j--)
		L.elem[j] = L.elem[j - 1];
	L.elem[i - 1] = e;
	L.size++;
	return true;
}

bool ListDelete(SqList &L, int i)
{
	if (i<1 || i>L.size)
		return false;
	for (int j = i - 1; j < L.size - 1; j++)
		L.elem[j] = L.elem[j + 1];
	L.size--;
	return true;
}

int main()
{
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 1, 2);
	ListDelete(L, 1);
	cout << L.elem[0] << endl;
	return 0;
}