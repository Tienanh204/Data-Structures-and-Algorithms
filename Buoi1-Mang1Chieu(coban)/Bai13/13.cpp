#include<iostream>
#include<math.h>
using namespace std;

#define MOD 1000000007

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
	long long tong = 0, tich = 1;

	for (int i = 0; i < n; i++)
	{
		tong = (tong + a[i]) % MOD;
		tich = (tich * a[i]) % MOD;
	}

	cout << tong << endl;
	cout << tich << endl;

}