#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "N-M: ";
	int n, m; cin >> n >> m;

	int* a = new int[n];
	int* b = new int[m];
	set<int> se;

	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "b[]: ";
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n; i++)
	{
		bool ok = false;

		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				ok = true;
				break;
			}
		}
		if (!ok)
		{
			se.insert(a[i]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		bool ok1 = false;

		for (int j = 0; j < n; j++)
		{
			if (b[i] != a[j])
			{
				ok1 = true;
				break;
			}
		}
		if (!ok1)
		{
			se.insert(b[i]);
		}
	}

	for (int x : se)
	{
		cout << x << " ";
	}
}