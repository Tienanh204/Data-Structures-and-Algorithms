#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100];
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}

	int res = 0;
	for (auto it : mp)
	{
		if (it.second > res)
		{
			res = it.second;
		}
	}

	for (auto it : mp)
	{
		if (it.second == res)
		{
			cout << it.first << " " << it.second << endl;
			break;
		}
	}

}