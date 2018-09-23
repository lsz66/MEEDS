#include <bits/stdc++.h>
#define Looper(i, n) for(int i = 0; i < n; i++)
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

void Print(vector<int> v)
{
	Looper(i, v.size())
		cout << v[i] << ' ';
	cout << endl;
}

int main()
{
	int arr[] = { 15,52,17,30,22,45,67,12,33,20 };
	vector<int> v(arr, arr + 10);
	SelectSort(v);
	Print(v);
	return 0;
}