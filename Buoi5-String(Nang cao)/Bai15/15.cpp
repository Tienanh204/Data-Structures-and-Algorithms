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
	string S, T;
	getline(cin, S);
	getline(cin, T);

	if (S.find(T) != string::npos)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}