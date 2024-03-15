#include<iostream>
#include<math.h>
#include<string>
using namespace std;
#define MOD 1000000007

long long rev(long long n)
{
	long long res = 0;
	long long tmp = n;
	while (tmp != 0)
	{
		long long x = tmp % 10;
		res = res * 10 + x;
		tmp /= 10;
	}
	return res;
}
long long pinbow(long long  a, long long b)
{
	if (b == 0)
	{
		return 1;
	}
	long long x = pinbow(a, b / 2);
	if (b % 2 == 0)
	{
		return ((x % MOD) * (x % MOD)) % MOD;
	}
	else
	{
		return ((x % MOD) * (x % MOD)) % MOD * (a % MOD) % MOD;
	}
}

int main()
{
	int n;
	cin >> n;
	cout << pinbow(n, rev(n)) << endl;
}