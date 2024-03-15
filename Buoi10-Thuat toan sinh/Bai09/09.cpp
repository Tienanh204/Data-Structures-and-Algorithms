#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n,k, final = 0;
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

vector<vector<int>> res;

int main()
{
	cin >> n >> k;
	vector<int>ch;
	for (int i = 0; i < k; i++)
	{
		int x; cin >> x;
		ch.push_back(x);
	}

	ktao();
	while (!final)
	{
		vector<int> tmp;
		for (int i = 1; i <= k; i++)
		{
			tmp.push_back(a[i]);
		}
		res.push_back(tmp);
		sinh();
	}

	int cnt = 0;
	for (int i = res.size()-1; i >=0 ; i--)
	{
		if (res[i] == ch)
		{
			cout << res.size() - i;
			break;
		}
	}
}