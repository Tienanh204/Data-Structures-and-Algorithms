#include<iostream>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s; cin >> s;
	multiset<char> se;

	for (int i = 0; i < s.size(); i++)
	{
		if (se.find(s[i]) == se.end())
		{
			se.insert(s[i]);
		}
	}

	int cnt1 = se.size();
	int cnt2 = 0;
	int res = INT_MAX;
	se.clear();

	for (int i = 0; i < s.size(); i++)
	{
		if (se.find(s[i]) == se.end())
		{
			cnt2++;
		}
		se.insert(s[i]);

		while (cnt2 == cnt1)
		{
			int temp = se.size();
			res = min(res, temp);
			
			se.erase(se.begin());
		}
	}
	cout << res << endl;
}