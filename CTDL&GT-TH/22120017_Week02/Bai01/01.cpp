#include<iostream>
#include<math.h>
#include<time.h>
#include<ctime>
#include<string>
using namespace std;

int fibo(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibo(n - 1) + fibo(n - 2);
}

int fibo1(int n)
{
	int fn1 = 1, fn2 = 0;
	if (n == 0)
		return fn2;
	if (n == 1)
		return fn1;

	int fn, tmp;
	for (int i = 2; i <= n; i++)
	{
		fn = fn1 + fn2;
		tmp = fn1;
		fn1 = fn;
		fn2 = tmp;
	}
	return fn;
}

/*
-So sanh thoi gian chay cua hai ham tren:
+De quy: goi di goilai cac phan tu nhieu lan gay ton bo nho va lau hon
+Vong lap: Nhanh hon vi chi duyet cac phan tu 1 lan
*/


int main()
{
	int n; cin >> n;
}