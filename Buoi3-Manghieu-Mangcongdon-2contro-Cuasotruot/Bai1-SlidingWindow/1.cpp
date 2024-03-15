#include<iostream>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>
#include<string>

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

	long long sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += a[i];
	}

	long long res = sum;
	int index = 0;

	for (int i = k; i < n; i++)
	{
		sum = sum - a[i - k] + a[i];

		if (sum > res)
		{
			res = sum;
			index = i - k + 1;
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << a[i + index] << " ";
	}

}