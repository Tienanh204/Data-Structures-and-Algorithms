#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include <utility>
#include <tuple>

using namespace std;

int main()
{
	cout << "N-M: ";
	int n, m; cin >> n >> m;
	
	int* a = new int[n];
	int* b = new int[m];

	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "B[]: ";
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	int i = 0, j = 0, k = 0;
	int* c = new int[m + n];

	while (i < n && j < m)
	{
		if (a[i] <= b[j])
		{
			c[k++] = a[i++];
		}
		else if (b[j] < a[i])
		{
			c[k++] = b[j++];
		}
	}

	while (i < n)
	{
		c[k++] = a[i++];
	}

	while (j < m)
	{
		c[k++] = b[j++];
	}

	cout << "C[]: ";
	for (int i = 0; i < n + m; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}