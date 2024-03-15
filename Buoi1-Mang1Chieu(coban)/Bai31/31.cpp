#include<iostream>
#include<math.h>
#include<map>
using namespace std;

int main()
{
	cout << "N-M-P: ";
	int n, m, p; cin >> n >> m >> p;

	int* a = new int[n+m];
	int* b = new int[m];

	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "b[]: ";
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	for (int i = n + p; i > n; i--)
	{
		a[i] = a[i - p - 1];
	}
	for (int i = 0; i < m ; i++)
	{
		a[i + p] = b[i];
	}
	for (int i = 0; i < m + n - 1; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;
	delete[] b;
}