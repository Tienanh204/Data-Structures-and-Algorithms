#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;

int cnt[10000001] = { 0 };
int main()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i]]++;
	}
	int nmin = INT_MAX;
	int nmax = INT_MIN;
	for (int i = 0; i < s.size(); i++)
	{
		nmin = min(nmin, cnt[s[i]]);
		nmax = max(nmax, cnt[s[i]]);
	}
	char cmin=' ', cmax=' ';

	for (int i = 0; i < s.size(); i++)
	{
		if (cnt[s[i]] == nmin)
		{
			cmin = max(cmin, s[i]);
		}
		if (cnt[s[i]] == nmax)
		{
			cmax = max(cmax, s[i]);
		}
	}
	cout << cmax << " " << nmax << endl;
	cout << cmin << " " << nmin << endl;
}