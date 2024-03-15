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

	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	//Xay dung mang hieu
	int* d = new int[n + 5];

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			d[i] = a[i];
		}
		else
		{
			d[i] = a[i] - a[i - 1];
		}
	}

	cout << "D[]: ";
	for (int i = 0; i < n; i++)
	{
		cout << d[i] << " ";
	}

	delete[]a;
}