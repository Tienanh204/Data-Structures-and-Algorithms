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

	int l = 0, r = 0;
	long long sum = 0;
	int res = INT_MAX;
	bool check = false;

	for (int r = 0; r < n; r++)
	{
		sum += a[r];

		while (sum >= s)
		{
			res = min(res, r - l + 1);
			sum -= a[l];
			l++;
			check = true;
		}

	}
	if (!check)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << res << endl;
	}
	
}

//7 20
//2 6 4 3 6 8 9