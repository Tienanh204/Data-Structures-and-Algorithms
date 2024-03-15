#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout << "N-X-K: ";
	int n, x, k; cin >> n >> x >> k;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = n; i >= k; i--)
	{
		a[i] = a[i - 1];
	}
	n++;
	a[k-1] = x;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

}