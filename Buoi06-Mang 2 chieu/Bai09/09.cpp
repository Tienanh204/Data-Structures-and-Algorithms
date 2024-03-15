#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int check(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return n > 1;
}

int main()
{
	int n; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	int j = n - 1;
	int k = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (check(a[i][j]))
		{
			cnt++;
		}
		if (check(a[i][k]))
		{
			cnt++;
		}
		j--;
		k++;
	}

	cout << cnt << endl;

	for (int i = 0; i < n; i++) delete[]a[i];
	delete[]a;
}