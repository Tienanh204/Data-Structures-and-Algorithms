#include<iostream>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int check(int* a, int l, int r, int k)
{
	set<int> se;
	for (int i = l; i <= r; i++)
	{
		se.insert(a[i]);
	}

	int res = *se.rbegin() - *se.begin();

	if (res <= k)
		return 1;
	else
		return 0;
}

int main()
{
	cout << "N-K: ";
	int n, k; cin >> n >> k;

	int* a = new int[n];

	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int l = 0;
	int res = 0;

	for (int r = 0; r < n; r++)
	{
		while (check(a, l, r, k) == 0)
		{
			l++;
		}
		res += r - l + 1;
	}
	cout << res << endl;
}