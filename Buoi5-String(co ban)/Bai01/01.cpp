#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{
	string s; cin >> s;
	if (s.size() % 2 == 0)
	{
		cout << "NOT FOUND" << endl;
	}
	else
	{
		cout << s[(s.size()) / 2] << endl;
	}
}