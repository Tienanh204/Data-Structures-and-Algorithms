#include<iostream>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

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

	int l = 0, r = n - 1;
	int m = l + 1;

	sort(a, a + n);

	bool check = false;

	while (l < m && m < r)
	{
		int sum = a[l] + a[r] + a[m];

		if (sum < k)
		{
			l++;
			m++;
		}
		else if (sum > k)
		{
			r--;
		}
		else if (sum == k)
		{
			check = true;
			break;
		}
	}
	if (check == true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}