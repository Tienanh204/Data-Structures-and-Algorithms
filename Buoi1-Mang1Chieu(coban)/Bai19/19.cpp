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
	
	for (int i = 0; i < n / 2; i++)
	{
		int tmp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = tmp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}