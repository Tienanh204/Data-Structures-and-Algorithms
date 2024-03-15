#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<map>
using namespace std;

int n, final = 0;
int a[100];

void ktao()
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = 0;
	}
}

void sinh()
{
	int i = n;
	while (i >= 1 && a[i] == 1)
	{
		a[i] = 0;
		i--;
	}

	if (i == 0)
		final = 1;
	else
	{
		a[i] = 1;
	}
}

bool check(int b[])
{
	for (int i = 0; i <= n / 2; i++)
	{
		if (b[i] != b[n - i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n;
	ktao();
	int b[100];

	while (!final)
	{
		for (int i = 1; i <= n; i++)
		{
			b[i] = a[i];
		}
		if (check(b))
		{
			for (int i = 1; i <= n; i++)
			{
				cout << b[i];
			}
			cout << endl;
		}
		sinh();
	}
}