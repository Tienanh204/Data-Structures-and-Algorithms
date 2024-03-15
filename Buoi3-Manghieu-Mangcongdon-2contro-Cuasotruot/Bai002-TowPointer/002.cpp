#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

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

	int i = 0, j = 0;

	while (i < n && j < m)
	{

		if (b[j] > a[i])
		{
			i++;
		}
		else
		{

			cout << i << " ";
			j++;
		}
	}

	while (j < m)
	{
		cout << j << " ";
		j++;
	}
}