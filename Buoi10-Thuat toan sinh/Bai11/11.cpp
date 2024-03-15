#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
using namespace std;
int n, cnt, final = 0;
int a[100];

void ktao()
{
	cnt = 1;
	a[1] = n;
}

void sinh()
{
	//Bat dau tu so hang cuoi cung va tim so hang dau tien !=1
	int i = cnt;
	while (i >= 1 && a[i] == 1)
	{
		i--;
	}
	if (i == 0)
		final = 1;
	else
	{
		int tmp = cnt - i + 1;
		a[i]--;
		cnt = i;
		int q = tmp / a[i];//tmp gap may lan a[i]
		int r = tmp % a[i];

		if (q != 0)
		{
			for (int j = 1; j <= q; j++)
			{
				a[i + j] = a[i];
			}
			cnt += q;
		}
		if (r != 0)
		{
			cnt++;
			a[cnt] = r;
		}
	}
}

int main()
{
	cin >> n;
	ktao();
	while (!final)
	{
		for (int i = 1; i <=cnt; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		sinh();
	}
}