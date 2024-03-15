#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<cmath>
#include<string>
#include<queue>
using namespace std;

bool increasing(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "N: ";
	int n; cin >> n;
	cout << "a[]: ";
	int a[100];
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int i = 0, j = n - 1;
	while (i != j)
	{
		if (a[i] > a[j])
		{
			swap(a[i], a[j]);
		}
		i++, j--;
	}
	if (increasing(a, n))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}