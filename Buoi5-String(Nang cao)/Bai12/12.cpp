#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <unordered_set>

using namespace std;

bool check(string s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s;
	getline(cin, s);

	stringstream ss(s);
	string token;

	string* a = new string[s.size() + 1];

	int k = 0;
	while (ss >> token)
	{
		if (check(token))
		{
			a[k++] = token;
		}
	}

	for (int i = 0; i < k - 1; i++) {
		int min = i;
		for (int j = i + 1; j < k; j++) {
			if (a[min].size() > a[j].size()) {
				min = j;
			}
		}
		swap(a[min], a[i]);
	}

	for (int i = 0; i < k; i++)
	{
		cout << a[i] << " ";
	}
}