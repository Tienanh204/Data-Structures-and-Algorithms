#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[m];

	int nmin = INT_MAX;
	int nmax = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x; cin >> x;
			a[i][j] = x;
			nmin = min(nmin, x);
			nmax = max(nmax, x);
		}
	}
	cout << nmin << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == nmin)
			{
				cout << i+1 << " " << j+1 << endl;
			}
		}
	}

	cout << nmax << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == nmax)
			{
				cout << i+1 << " " << j+1 << endl;
			}
		}
	}

	for (int i = 0; i < m; i++) delete[]a[i];
	delete[]a;
}