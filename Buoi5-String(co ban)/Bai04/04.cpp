#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

int main()
{
	string s; cin >> s;
	bool check = true;
	for (int i = 0; i < s.size()-1; i++)
	{
		int x = std::stoi(s.substr(i + 1, 1)) - std::stoi(s.substr(i, 1));
		if (abs(x) != 1) {
			check = false;
			break;
		}
	}
	if (check) {
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}