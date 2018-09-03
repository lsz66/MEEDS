const int MAXSIZE = 50;
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

void initStack(SqStack &S)
{
    S.top = -1;
}

bool isEmpty(SqStack S)
{
    return S.top == -1;
}

bool isFull(SqStack S)
{
    return S.top + 1 == MAXSIZE; //数组下标=总大小-1
}

bool push(SqStack &S, ElemType e)
{
    if (isFull(S))
        return false;
    S.data[++S.top] = e;
    return true;
}

bool pop(SqStack &S, ElemType &e)
{
    if (isEmpty(S))
        return false;
    e = S.data[S.top--];
    return true;
}

bool getTop(SqStack S, ElemType &e)
{
    if (isEmpty(S))
        return false;
    e = S.data[S.top];
    return true;
}