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

	bool check = true;

	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			check = false;
			break;
		}
	}
	if (check)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}