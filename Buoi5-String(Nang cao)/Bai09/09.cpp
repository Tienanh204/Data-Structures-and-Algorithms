#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<sstream>
#include<set>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]==',')
		{
			s[i] = ' ';
		}
	}

	stringstream ss(s);
	string token;
	int cnt = 0;

	while (ss >> token)
	{
		cnt++;
	}
	cout << cnt << endl;
}