#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[m]) > abs(a[j]))
			{
				m = j;
			}
		}
		swap(a[m], a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}