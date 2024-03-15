#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;


int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	set<char> se;

	for (int i = 0; i < s1.size(); i++)
	{
		bool ok = true;
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			se.insert(s1[i]);
		}
	}
	for (auto it : se)
	{
		cout << it;
	}
	cout << endl;
	se.clear();

	for (int i = 0; i < s2.size(); i++)
	{
		bool ok = true;
		for (int j = 0; j < s1.size(); j++)
		{
			if (s2[i] == s1[j])
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			se.insert(s2[i]);
		}
	}
	for (auto it : se)
	{
		cout << it;
	}
}