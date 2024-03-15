#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	cout << "N: ";
	int n; cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int* f = new int[n];

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			f[0] = a[i];
		else
			f[i] = f[i - 1] + a[i];
	}

	cout << "F[]: ";
	for (int i = 0; i < n; i++)
	{
		cout << f[i] << " ";
	}
	cout << endl;

}