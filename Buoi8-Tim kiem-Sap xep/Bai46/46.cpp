#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

//Y tuong: Binary search on answer

bool check(int a[], int n, int h, int m)
{
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > m)
		{
			res += a[i] - m;
		}
	}
	return res >= h;
}

int main()
{
	int n, h; cin >> n >> h;

	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	long long l = 0, r =(long long)*(min_element(a, a + n)) * h;
	
	int m;
	int ans = -1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (check(a, n, h, m))
		{
			l = m + 1;
			ans = m;
		}
		else
		{
			r = m - 1;
		}
	}
	cout << ans << endl;
}