#include<iostream>
#include<math.h>
#include<string>
using namespace std;

#define MOD 1000000007

/*
        { 1, b=0
  a^b = { a^(b/2) * a^(b/2), b chan
        { a^(b/2) * a^(b/2) * a, b le
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
		return ((x%MOD) * (x%MOD)) % MOD;
	}
	else
	{
		return ((x % MOD) * (x % MOD)) % MOD * (a % MOD) % MOD;
	}
}

//Do phuc tap: log2(N)

int main()
{
	long long n, k;
	cin >> n >> k;
	cout << pinbow(n, k) << endl;
}