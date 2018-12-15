#include <bits/stdc++.h>
using namespace std;

void StraightInsertionSort(vector<int> &a)
{
	int pos;	//要插入的位置
	for (int i = 2; i < a.size(); i++)	//逐步扩大已排序序列
		if (a[i] < a[i - 1])	//若待排序元素小于其前面的元素，说明要寻找前面相对于位置插入
		{
			a[0] = a[i];	//保存待排序元素
			for (pos = i - 1; a[0] < a[pos]; pos--)	//后移其他元素
				a[pos + 1] = a[pos];
			a[pos + 1] = a[0];	//待排序元素插入
		}
}

void BinaryInsertionSort(vector<int> &a)
{
	int i, j, low, high, mid;
	for (i = 2; i < a.size(); i++)
	{
		a[0] = a[i];
		low = 1; high = i - 1;	//折半查找范围，即已排序范围
		while (low<=high)
		{
			mid = (low + high) / 2;
			if (a[mid] > a[0])
				high = mid - 1;
			else
				low = mid + 1;
		}	//折半查找，找到插入位置
		for (j = i - 1; j >= high + 1; j--)
			a[j + 1] = a[j];
		a[high + 1] = a[0];
	}
}

void ShellSort(vector<int> &a)
{
	int n = a.size()-1;
	for (int dk = n / 2; dk; dk /= 2)
	{
		for (int i = dk + 1; i <= n; i++)
		{
			if (a[i] < a[i - dk])
			{
				a[0] = a[i];
				int j;
				for (j = i - dk; j > 0 && a[0] < a[j]; j -= dk)
					a[j + dk] = a[j];
				a[j + dk] = a[0];
			}
		}
	}
}

void Print(vector<int> v)
{
	for (int i = 1; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}

int main()
{
	vector<int> v{ 0,5,4,3,2,1 };
	ShellSort(v);
	Print(v);
	return 0;
}