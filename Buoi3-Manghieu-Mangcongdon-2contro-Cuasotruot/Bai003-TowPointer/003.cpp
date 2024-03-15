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

	int cnt = 0;

	while (i<n && j<m)
	{
		if (a[i] > b[j])
		{
			j++;
			continue;
		}
		else if (a[i] < b[j])
		{
			i++ ; 
			continue;
		}
		int dem1 = 0, dem2 = 0;

		while (i<n && a[i] == b[j])
		{
			dem1++; i++;
		}

		int temp = a[i - 1];

		while (j< m && temp == b[j])
		{
			dem2++, j++;
		}

		cnt += dem1 * dem2;
	}
	
	cout << cnt << endl;
}