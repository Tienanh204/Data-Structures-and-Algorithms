#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <unordered_set>
#include<vector>

using namespace std;

int main()
{
	int stt;
	cin >> stt;
	cin.ignore();

	while (stt--)
	{
		vector<string> v;
		string s;
		getline(cin, s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		stringstream ss(s);
		string token;
		while (ss >> token)
		{
			v.push_back(token);
		}

		int n = v.size();
		string email = v[n - 2];

		for (int i = 0; i < n - 2; i++)
		{
			email += v[i][0];
		}
		cout << email << "@xyz.edu.vn" << endl;

		string date = v[n - 1];
		stringstream ss1(date);
		while (getline(ss1, token, '/'))
		{
			cout << stoi(token);
		}
	}
}