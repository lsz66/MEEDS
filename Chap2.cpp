// 2.2.3

//1.
int delMin(SqList &L)
{
	if (!L.length)
	{
		cout << "顺序表为空" << endl;
		exit(0);
	}
	int pos = 0, minVal = L.elem[0];
	for (int i = 1; i < L.length; i++)
	{
		if (L.elem[i] < minVal)
		{
			minVal = L.elem[i];
			pos = i;
		}
	}
	L.elem[pos] = L.elem[L.length - 1];
	L.length--;
	return minVal;
}

//2.
