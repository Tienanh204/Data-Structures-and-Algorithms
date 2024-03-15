#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, k, s;
int x[100];
int a[100];
int sum , cnt;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
}

void Try(int i, int bd, int sum)
{
	for (int j = bd; j <= n; j++)
	{
		x[j] = j;
		if (i == k)
		{
			if (sum + j == s)
				cnt++;
		}
		else
		{
			Try(i + 1, j + 1, sum + j);
		}
	}
}

int main()
{
	cin >> n >> k >> s;
	init();
	Try(1,1,0);
	cout << cnt << endl;
}