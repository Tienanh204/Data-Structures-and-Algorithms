#include<iostream>
#include<math.h>
#include<string>
using namespace std; 

long long tinh(long long n, long long k)
{
	long long x = pow(2, n - 1);
	if (x == k)//Neu phan tu can tim nam o vi tri trung tam luon
		return n;
	if (k > x)//Neu phan tu can tim o ben phai thi minh qua ben trai tim (vi no doi xung)
		return tinh(n, k - x);
	else //Con neu ben trai roi thi tinh bth
		return tinh(n - 1, k);
}


int main()
{
	long long n, k;
	cin >> n >> k;
	cout << tinh(n, k) << endl;
}