#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<map>
using namespace std;

int n, k, final = 0;
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
	int i = k;
	while (i >= 1 && a[i] == n - k + i)
	{
		i--;
	}
	if (i == 0)
		final = 1;
	else
	{
		a[i]++;
		for (int j = i + 1; j <= k; j++)
		{
			a[j] = a[j - 1] + 1;
		}
	}
}

int main()
{
	cin >> n >> k;
	vector<int> tmp;
	for (int i = 0; i < k; i++)
	{
		int x; cin >> x;
		tmp.push_back(x);
	}
	ktao();
	map<int, int> mp;
	while (!final)
	{
		vector<int> tmp1;
		for (int i = 1; i <= k; i++)
		{
			cout << a[i];
			tmp1.push_back(a[i]);
			mp[a[i]]++;
		}
		cout << endl;
		if (tmp1 == tmp)
		{
			break;
		}
		sinh();
	}
	cout << n - mp.size() << endl;
}