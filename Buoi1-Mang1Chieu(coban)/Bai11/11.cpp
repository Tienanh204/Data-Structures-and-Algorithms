#include<iostream>
#include<math.h>
using namespace std;


int fibo[90];

void Fibo()
{
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;

	for (int i = 3; i < 90; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}

int check(int n)
{
	for (int i = 0; i < 90; i++)
	{
		if (n == fibo[i])
			return 1;
	}
	return 0;
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
	Fibo();
	for (int i = 0; i < n; i++)
	{
		if (check(a[i]))
		{
			cout << a[i] << " ";
		}
	}

}