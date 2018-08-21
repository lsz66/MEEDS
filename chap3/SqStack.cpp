#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 50;
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} Stack;

void initStack(Stack &S)
{
    S.top = -1;
}

bool isEmpty(Stack S)
{
    return S.top == -1;
}

bool isFull(Stack S)
{
    return S.top + 1 == MAXSIZE; //数组下标=总大小-1
}

bool push(Stack &S, ElemType e)
{
    if (isFull(S))
        return false;
    S.data[++S.top] = e;
    return true;
}

bool pop(Stack &S, ElemType &e)
{
    if (isEmpty(S))
        return false;
    e = S.data[S.top--];
    return true;
}

bool getTop(Stack S, ElemType &e)
{
    if (isEmpty(S))
        return false;
    e = S.data[S.top];
    return true;
}