#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
using namespace std;
int n,k, final = 0;
int a[100];

void ktao()
{
	for (int i = 1; i <= k; i++)
	{
		a[i] = 1;
	}
}

void sinh()
{
	int i = n;
	while (i >= 1 && a[i] != a[i + 1])
	{
		i--;
	}
	if (i == 0)
	{
		final = 1;
	}
	else
	{

	}
}
int main()
{
	cin >> n >> k;
	ktao();

}