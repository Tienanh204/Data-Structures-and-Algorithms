#include<iostream>
#include<math.h>
#include<string>
using namespace std;
#define MOD 1000000007
long long F[1000001];
int n, k;
string s1, s2;

void ktao()
{
	F[1] = 1; F[2] = 1;
	for (int i = 3; i <= 92; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
}
//Y tuong: Chuoi thu n = chuoi thu n-1 + chuoi thu n - 2
//ta kiem tra xem k thuoc pham vi trong chuoi nao thi goi de quy den chuoi do
char fibo(int n, long long k)
{
	if (n == 1)
	{
		return 'A';
	}
	if (n == 2)
	{
		return 'B';
	}
	if (k <= F[n - 2])
	{
		return fibo(n - 1, k);
	}
	else
	{
		return fibo(n - 1, k - F[n-2]);
	}
}

int main()
{
	cin >> n >> k;

	//Cach 1: doi voi bai taon test case nho
	//string s1 = "A";
	//string s2 = "B";
	//string sn = "";
	//for (int i = 3; i <= n; i++)
	//{
	//	sn = s1 + s2;
	//	s1 = s2;
	//	s2 = sn;
	//}
	//cout << sn << endl;
	//cout << sn[k-1] << endl;

	//Cach 2: Chia de tri
	ktao();
	cout << fibo(n, k) << endl;
}