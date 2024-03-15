#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
using namespace std;

int n, k, final = 0;
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
		b[i] = i;
	}
	ktao();

	vector<vector<int>> res;

	while (!final)
	{
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			v.push_back(a[i]);
		}
		res.push_back(v);
		sinh();
	}

	sort(res.begin(), res.end());
	int Size = res.size();
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (res[i][j] == 1)
			{
				cout << j + 1 << " ";
			}
		}
		cout << endl;
	}
}