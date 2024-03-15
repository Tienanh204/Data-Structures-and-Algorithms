#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout << "N-K: ";
	int n, k; cin >> n >> k;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i <= n - k; i++)
	{
		int s = 0;
		for (int j = 0; j < k; j++)
		{
			s += a[i + j];
		}
		cout << s << " ";
	}
	cout << endl;
}