#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
using namespace std;

int n, final = 0;
int a[100];

void ktao()
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
}

void sinh()
{
	int i = n;
	while (i >= 1 && a[i]>a[i+1])
	{
		i--;
	}
	if (i == 0)
		final = 1;
	else
	{
		int j = n;
		while (a[i] > a[j]) j--;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

void main()
{
	string s;
	cin >> s;
	n = s.size();

	ktao();
	char b[100];

	for (int i = 1; i <= n; i++)
	{
		b[i-1] = s[i - 1];
	}

	while (!final)
	{
		for (int i = 1; i <= n; i++)
		{
			int index = a[i];
			cout << b[index - 1];
		}
		cout << endl;
		sinh();
	}
}