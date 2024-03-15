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
	unordered_set<string> se;

	stringstream ss(s);
	string token;

	while (ss >> token)
	{
		mp[token]++;
		se.insert(token);
	}

	for (auto it : mp)
	{
		cout << it.first << " " << it.second << endl;
	}
	cout << endl;
	for (auto it : se)
	{
		cout << it << " " << mp[it] << endl;
	}
}