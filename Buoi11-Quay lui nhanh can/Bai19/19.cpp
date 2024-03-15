#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<vector>
using namespace std;

int n;
int a[100];
int x[100];

vector<vector<int>> res;

void Try(int i, int index, int sum)
{
	for (int j = index; j < n; j++)
	{
		sum += a[j];
		x[i] = a[j];
		if (sum % 2 != 0)
		{
			vector<int> tmp(x + 1, x + i + 1);
			res.push_back(tmp);
		}
		Try(i + 1, j + 1, sum);
		sum -= a[j];
	}
}

int main()
{
	cout << "N: ";
	cin >> n;
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	Try(1,0,0);
	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}