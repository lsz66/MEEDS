#include <bits/stdc++.h>
#define Looper(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef char* String;

String Create(const char* source)
{
	size_t len = strlen(source);
	String dst = new char[len + 1];
	dst[0] = len;
	strcpy(dst + 1, source);
	return dst;
}

int BruteForce(String s, String t)	//字符串下标从1开始
{
	int i = 1, j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (s[i] == t[j])
		{
			i++; 
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t[0])
		return i - t[0];
	else
		return 0;
}

int* GetNext(String t)
{
	int *next = new int[strlen(t) + 1];
	next[1] = 0;
	int i = 1, j = 0;
	while (i < t[0])
	{
		if (j == 0 || t[i] == t[j])	
			next[++i] = ++j;
		else
			j = next[j];
	}
	return next;
}

int KMP(String s, String t)
{
	int *next = GetNext(t);
	int i = 1, j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (j == 0 || s[i] == t[j])	//如果j=0，代表当前主串字符与模式串第一个字符不匹配，ij++，注意j++后才是模式串第一个字符
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > t[0])
		return i - t[0];
	else
		return 0;
}

int main()
{
	String s = Create("abcabcdabca");
	String t = Create("abcdabca");
	cout << KMP(s, t) << endl;
	return 0;
}