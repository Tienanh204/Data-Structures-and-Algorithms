#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	cout << "N-S: ";
	int n, s; cin >> n >> s;

	int* a = new int[n];

	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int l = 0;
	long long sum = 0;
	int res = 0;

	for (int r = 0; r < n; r++)
	{
		sum += a[r];

		while (sum >= s)
		{
			res += n - r;
			sum -= a[l];
			l++;
		}

	}

	cout << res << endl;
}