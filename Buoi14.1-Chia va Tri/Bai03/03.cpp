#include<iostream>
#include<math.h>
#include<string>
using namespace std;
#define MOD 1000000007

/*
- Dung kien thuc sau: x1 + x2 + ... + xn = r
-> (n+r-1)C(n-1) la so nghiem ua phuong trinh xi>=1
*/

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
	long long n; cin >> n;
	cout << pinbow(2, n - 1);
}