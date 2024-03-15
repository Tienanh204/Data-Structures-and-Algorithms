#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int n, k, a[100];
int final = 0;

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
		sort(a + i + 1, a + n + 1);
	}
}

int main()
{
	vector<vector<int>>v;
	cin >> n;
	ktao();
	while (!final)
	{
		vector<int> tmp;
		for (int i = 1; i <= n; i++)
		{
			tmp.push_back(a[i]);
		}
		v.push_back(tmp);
		sinh();
	}
	for (int i = v.size()-1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[i][j];
		}
		cout << endl;
	}
}