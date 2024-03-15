#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<map>
using namespace std;

int n, final = 0;
char a[100];

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
	while (i >= 1 && a[i] > a[i + 1])
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

int main()
{
	
}
