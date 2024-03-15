#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

//Y tuong: Binary search on answer

bool check(int a[], int n, int k, int m)
{
	long long cnt = 0;
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += a[i];
		if (res > m)
		{
			cnt++;
			res = a[i];
		}
	}
	cnt++;

	return cnt <= k;
}

int main()
{
	int n, k; cin >> n >> k;
	int a[100];

	long long r = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		r += a[i];
	}

	long long l = (long long)max_element(a, a + n);

	long long m;
	long long res = -1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (check(a, n, k, m))
		{
			r = m - 1;
			res = m;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << res << endl;
}