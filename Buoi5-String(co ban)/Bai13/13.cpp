#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.' || s[i] == ',' || s[i] == '?' || s[i] == '!')
		{
			s[i] = ' ';
		}
	}
	stringstream ss(s);
	string w;
	while (ss >> w)
	{
		cout << w << " ";
	}
}