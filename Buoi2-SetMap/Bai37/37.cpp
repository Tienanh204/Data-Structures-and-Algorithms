#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<iomanip>
#include<vector>
using namespace std;


int main()
{
	cout << "********** INPUT **********" << endl;
	string s;

	map<string, vector<pair<int,int>>> mp;

	while (cin>>s)
	{
		int tin, diem;
		cin >> tin >> diem;

		mp[s].push_back({ tin, diem });
	}

	for (auto it = mp.rbegin(); it != mp.rend(); it++)
	{
		cout << (*it).first << ": ";

		float tu = 0, mau = 0;

		for (int i = 0; i < (*it).second.size(); i++)
		{
			tu += (*it).second[i].first * (*it).second[i].second;
			mau += (*it).second[i].first;
		}

		if(mau!=0)
		cout << fixed << setprecision(2) << tu / mau << endl;

	}
}