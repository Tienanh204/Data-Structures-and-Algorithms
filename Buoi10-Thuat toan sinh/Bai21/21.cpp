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
		a[i] = 1;
}

int main()
{
	cin >> n;
	int b[100];
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}

	int res = INT_MAX;

	while (!final)
	{
		int gr1 = 0, gr2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				gr1 += b[i];
			}
			if (a[i] == 1)
			{
				gr2 += b[i];
			}
		}
		res = min(res, abs(gr2 - gr1));
		sinh();
	}
	cout << res << endl;
}
