#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "N: ";
	int n; cin >> n;

	map<string, string> mp;

	cin.ignore();

	while (n--)
	{
		string id, name;
		cout << "ID: ";
		getline(cin, id);
		cout << "Name: ";
		getline(cin, name);

		mp[id] = name;
	}

	cout << "Q: ";
	int q; cin >> q;
	cin.ignore();

	while (q--)
	{
		string ms;
		getline(cin, ms);
		bool check = false;

		for (auto it : mp)
		{
			if (it.first == ms)
			{
				cout << it.second << endl;
				check = true;
			}
		}
		if (!check)
		{
			cout << "NOT FOUND" << endl;
		}
	}
}