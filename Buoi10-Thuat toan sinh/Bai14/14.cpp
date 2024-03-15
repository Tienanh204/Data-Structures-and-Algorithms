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
	vector<vector<int>> res;

	ktao();

	while (!final)
	{
		vector<int> v;
		int cnt1 = 0,cnt2 = 0;
		int res1 = INT_MIN, res2 = INT_MIN;
		bool check = false;
		if (a[1] == 1 && a[n] == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				v.push_back(a[i]);
				if (a[i] == 0 && a[i + 1] == 0)
				{
					cnt1++;
				}
				else
				{
					res1 = max(cnt1, res1);
					cnt1 = 0;
				}
				if (a[i] == 1 && a[i + 1] == 1)
				{
					cnt2++;
				}
				else
				{
					res2 = max(cnt2, res2);
					cnt2 = 0;
				}
			}
		}
		if (cnt1 < 2 && cnt2 < 1)
		{
			res.push_back(v);
		}
		sinh();
	}

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (res[i][j] == 1)
			{
				cout << "8";
			}
			if (res[i][j] == 0)
			{
				cout << "6";
			}
		}
		cout << endl;
	}

}