#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout << "N: ";
	int n, k; cin >> n;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int i = 0;

	while(i<n)
	{
		if (a[i] == a[i + 1])
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
		}
		else
		{
			i++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}