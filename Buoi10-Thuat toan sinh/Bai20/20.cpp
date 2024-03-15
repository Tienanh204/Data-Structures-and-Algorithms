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

void ktao(int k)
{
	for (int i = 1; i <= k; i++)
	{
		a[i] = 0;
	}
}

void sinh(int k)
{
	int i = k;
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

bool check(vector<int> &tmp, int k)
{
	for (int i = 1; i <= k / 2; i++)
	{
		if (tmp[i-1] != tmp[k - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n;
	vector<vector<int>> res;
	for (int k = 2; k <= n; k += 2)
	{
		ktao(k);
		while (!final)
		{
			vector<int> tmp;
			for (int i = 1; i <= k; i++)
			{
				tmp.push_back(a[i]);
			}
			if (check(tmp,k))
			{
				res.push_back(tmp);
			}
			sinh(k);
		}
		final = 0;
	}

	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j];
		}
		cout << endl;
	}
}