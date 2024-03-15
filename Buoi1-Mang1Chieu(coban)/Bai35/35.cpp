#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout << "N: ";
	int n, m; cin >> n ;
	int* a = new int[n];
	int* b = new int[n-1];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "b[]: ";
	for (int i = 0; i < n-1; i++)
	{
		cin >> b[i];
	}

	int s = a[0];

	int j = 1;

	for (int i = 0; i < n-1; i++)
	{
		if (b[i] == 1)
		{
			s += a[j];
			j++;
		}
		else if (b[i] == 2)
		{
			s -= a[j];
			j++;
		}
	}
	cout << s << endl;
}