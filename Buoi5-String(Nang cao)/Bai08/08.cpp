#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int main()
{
	string s; cin >> s;
	transform(s.begin(), s.end(),s.begin( ),::tolower);

	set<char>se;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			se.insert(s[i]);
		}
	}

	if (se.size() == 26)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

}