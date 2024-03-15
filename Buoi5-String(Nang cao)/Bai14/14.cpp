#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	map<string, int> mp;

	stringstream ss(s);
	string token;
	string* a = new string[s.size() + 1];
	int k = 0;

	while (ss >> token)
	{
		mp[token]++;
		a[k++] = token;
	}
	int nmin = INT_MAX;
	int nmax = INT_MIN;
	for (int i = 0; i < k; i++)
	{
		nmin = min(nmin, mp[a[i]]);
		nmax = max(nmax, mp[a[i]]);
	}
	string cmax, cmin;

	for (int i = 0; i < k; i++)
	{
		if (mp[a[i]] == nmin)
		{
			cmin = max(cmin, a[i]);
		}
		if (mp[a[i]] == nmax)
		{
			cmax = max(cmax, a[i]);
		}
	}
	cout << cmax << " " << nmax << endl;
	cout << cmin << " " << nmin << endl;
}