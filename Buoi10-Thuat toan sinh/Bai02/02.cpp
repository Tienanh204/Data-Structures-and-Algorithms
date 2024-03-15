#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, k, a[100];
int final = 0;

void ktao()
{
	for (int i = 1; i <= k; i++)
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
vector<vector<int>>res;
int main()
{
	cin >> n >> k;
	vector<int> tmp;
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		tmp.push_back(x);
	}
	ktao();

	while (!final)
	{
		vector<int> tmp1;
		for (int i = 1; i <= k; i++)
		{
			tmp1.push_back(a[i]);
		}
		res.push_back(tmp1);
		sinh();
	}
	int size = res.size() - 1;

	for (int i = 0; i <=size; i++)
	{
		if (res[i] == tmp)
		{
			for (int j = 0; j < k; j++)
			{
				cout << res[(i+1) % size][j] << " ";
			}
			break;
		}
	}
}
