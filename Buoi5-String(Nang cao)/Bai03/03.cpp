#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	string s; cin >> s;
	string s_tmp = s;
	int cnt1[10000] = { 0 };
	int cnt2[10000] = { 0 };

	for (int i = 0; i < s.size(); i++)
	{
		cnt1[s[i]]++;
		cnt2[s[i]]++;
	}

	sort(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++)
	{
		if (cnt1[s[i]] >= 1)
		{
			cout << s[i] << " " << cnt1[s[i]] << endl;
			cnt1[s[i]] = 0;
		}
	}
	cout << endl;
	for (int i = 0; i < s_tmp.size(); i++)
	{
		if (cnt2[s_tmp[i]] >= 1)
		{
			cout << s_tmp[i] << " " << cnt2[s_tmp[i]] << endl;
			cnt2[s_tmp[i]] = 0;
		}
	}
}