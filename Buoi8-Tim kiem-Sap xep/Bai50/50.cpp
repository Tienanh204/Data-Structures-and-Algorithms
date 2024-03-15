#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

//Y tuong: Binary search on answer

bool check(long long n, long long x, long long y, long long time)
{
	time -= min(x, y);
	return time / x + time / y >= n - 1;
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;

	long long l = 0, r = (long long)min(x, y) * n;
	long long ans = -1;
	while (l <= r)
	{
		long long m = (l + r) / 2;
		if (check(n, x, y, m))
		{
			ans = m;
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << ans << endl;
}