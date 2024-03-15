#include<iostream>
#include<string>
#include<vector>
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
	{
		final = 1;
	}
	else
	{
		int j = n;
		while (a[i] > a[j]) j--;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);// Ta cung co the dung sort(a+i+1,a+n+1)
	}
}

vector<vector<int>>res;

int main()
{
	cin >> n;
	vector<int> tmp;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		tmp.push_back(x);
	}
	ktao();

	while (!final)
	{
		vector<int> tmp1;
		for (int i = 1; i <= n; i++)
		{
			tmp1.push_back(a[i]);
		}
		res.push_back(tmp1);
		sinh();
	}

	int size = res.size()-1;
	for (int i = 0; i <= size; i++)
	{
		if (res[i] == tmp)
		{
			for (int j = 0; j < n; j++)
			{
				cout << res[(i+1) % size][j] << " ";
			}
			break;
		}
	}
}