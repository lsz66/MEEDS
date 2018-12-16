#include <bits/stdc++.h>
#define Looper(i, n) for(int i = 0; i < n; i++)
using namespace std;

void BubbleSort(vector<int> &v)
{
	int n = v.size();	//-1不能放在这里因为内层for循环需要用到n位
	for (int i = 0; i < n - 1; i++)	//只需排序到n-1位，之前的序列排序号最后一位自然排序好
	{
		bool isChange = false;
		for (int j = n - 1; j > i; j--)	//控制冒泡范围，从表头到表尾，表头先有序
		{
			if (v[j - 1] > v[j])	//前方元素比后方大
			{
				swap(v[j - 1], v[j]);
				isChange = true;
			}
			if (!isChange)
				return;
		}
	}
}

int main()
{
	vector<int> v{ 5,4,3,2,1 };
	BubbleSort(v);
	Looper(i, v.size())
		cout << v[i] << ' ';
	return 0;
}