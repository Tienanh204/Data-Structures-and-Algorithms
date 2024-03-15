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
	sort(a, a + n);
	int l = 0, r = n - 1;
	int m = l + 1, o = r - 1;
	bool check = false;

	while (l < m && m < o && o < r)
	{
		int sum = a[l] + a[r] + a[m] + a[o];

		if (sum < k)
		{
			l++;
			m++;
		}
		else if (sum > k)
		{
			r--;
			o--;
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