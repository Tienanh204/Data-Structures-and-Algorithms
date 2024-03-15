#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
int a[1000001], n;

// 1. Tim kiem tuan tu
//1.1 Tim kiem tuan tu vet can (Exhaustive Linear)
int LinearExhaustive(int a[], int n, int x) 
{
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

//1.2 Tim kiem tuan tu linh canh (Sentinel Linear)
int LinearSentinel(int a[], int n, int x)
{
	a[n] = x;
	for (int i = 0; ; i++)
	{
		if (a[i] == x) 
		{
			return i;
		}
	}
}

//2. Tim kiem nhi phan (Binary search)
int binarySearch1(int a[], int n, int x)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] == x)
			return m;
		else
		{
			if (a[m] < x)
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
	}
	return -1;
}

bool binarySearch1(int a[], int l, int r, int x)
{
	if (l>r)
		return false;
	else
	{
		int m = (l + r) / 2;
		if (a[m] == x)
			return true;

		if (a[m] < x)
		{
			return binarySearch1(a, m + 1, r, x);
		}
		else
		{
			return binarySearch1(a, l, m - 1, x);
		}
	}
}