#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

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

	int res = a[0];

	for (int i = 1; i < n; i++)
	{
		res = gcd(res, a[i]);
	}
	cout << res << endl;
}