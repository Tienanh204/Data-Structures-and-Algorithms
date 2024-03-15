#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

bool check(int n)
{
	int tmp = n;
	int res = 0;
	while (tmp != 0)
	{
		res = res * 10 + tmp % 10;
		tmp /= 10;
	}
	return res == n;
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
			int x; cin >> x;
			a[i][j] = x;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (check(a[i][j]))
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;

	for (int i = 0; i < n; i++) delete[]a[i];
	delete[]a;
}
