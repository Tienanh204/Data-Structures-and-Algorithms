#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout << "n: ";
	int n; cin >> n;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bool ok = true;

	for (int i = 0; i < n / 2; i++)
	{
		if (a[i] != a[n - i - 1])
		{
			ok = false;
		}
	}

	if (ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}