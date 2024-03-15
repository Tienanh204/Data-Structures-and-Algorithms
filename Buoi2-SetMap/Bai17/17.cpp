#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "chuoi: ";
	char temp[100];
	cin.getline(temp, 90);
	map<char, int> mp;

	for (int i = 0; i < strlen(temp); i++)
	{
		mp[temp[i]]++;
	}

	int res1 = INT_MIN;
	int res2 = INT_MAX;

	for (auto it : mp)
	{
		if (it.second > res1)
		{
			res1 = it.second;
		}

		if (it.second < res2)
		{
			res2 = it.second;
		}
	}

	for (auto it : mp)
	{
		if (it.second == res1)
		{
			cout << it.first << " " << it.second << endl;
			break;
		}
	}

	for (auto it = mp.rbegin(); it != mp.rend(); it++)
	{
		if ((*it).second == res2)
		{
			cout << (*it).first << " " << (*it).second << endl;
			break;
		}
	}
	cout << mp.size() << endl;
}