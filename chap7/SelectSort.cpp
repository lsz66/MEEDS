#include <bits/stdc++.h>
#define Looper(i, n) for (int i = 0; i < n; i++)
#define For(i, s, t) for (int i = s; i < t; i++)
using namespace std;

void SelectSort(vector<int> &v)
{
	Looper(i, v.size() - 1)
	{
		int minN = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[minN] > v[j])
				minN = j;
		if (minN != i)
			swap(v[i], v[minN]);
	}
}

void AdjustDown(int a[], int k, int len)
{
	//k:父(待调整), i:子, 0:暂存空间
	a[0] = a[k];
	for (int i = 2 * k; i <= len; i *= 2) //检查当前节点的儿子
	{
		//数组下标从1开始，0作交换辅助空间
		if (i < len && a[i] < a[i + 1]) //若有右儿子且右儿子比左儿子大
			i++;
		if (a[0] >= a[i]) //根比俩儿子都大
			break;
		else
		{
			a[k] = a[i];
			k = i;
		}
	}			 //继续检查一下调整后的那个节点的儿子们
	a[k] = a[0]; //将最大的节点放到最后的位置，就是这轮的最大值。
}

void BuildMaxHeap(int a[], int len)
{
	for (int i = len / 2; i > 0; i--)
		AdjustDown(a, i, len);
}

void HeapSort(int a[], int len)
{
	BuildMaxHeap(a, len);
	for (int i = len; i > 1; i--)
	{
		swap(a[i], a[1]);
		cout << a[i] << ' ';
		AdjustDown(a, 1, i - 1);
	}
}

void Print(vector<int> v)
{
	Looper(i, v.size())
			cout
		<< v[i] << ' ';
	cout << endl;
}

int main()
{
	int arr[] = {0, 15, 52, 17, 30, 22, 45, 67, 12, 33, 20};
	cout << "选择排序：" << endl;
	vector<int> v(arr + 1, arr + 11);
	SelectSort(v);
	Print(v);
	cout << "==========================" << endl;
	cout << "堆排序：" << endl; //堆排序不工作
	HeapSort(arr, 10);
	return 0;
}