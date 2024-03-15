#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int Findpos(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '-') return i;
	}

	return 0;
}

int main()
{
	cout << "N: ";
	int n; cin >> n;
	map<string, vector<string>>mp;
	cin.ignore();

	string s;

	while (getline(cin, s) && n != 0)
	{
		string team1, team2;
		int pos = Findpos(s);

		team1 = s.substr(0, pos - 1);
		team2 = s.substr(pos + 2);

		mp[team1].push_back(team2);
		mp[team2].push_back(team1);

		n--;
	}

	cout << "*************** OUTPUT **************" << endl;
	for (auto it : mp)
	{
		sort(it.second.begin(), it.second.end());

		cout << it.first <<": ";
		for (int i = 0; i < it.second.size(); i++)
		{
			cout << it.second[i];
			if (i < it.second.size() - 1)
			{
				cout << ", ";
			}
		}
		cout << endl;
	}
}