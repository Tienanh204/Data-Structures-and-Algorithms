#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s; cin >> s;
	bool ok = false;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '0')
		{
			s[i] = '1';
			ok = true;
			break;
		}
	}
	if (!ok)
	{
		for (int i = 0; i < s.size(); i++)
		{
			cout <<"0";
		}
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			cout << s[i];
		}
	}
}