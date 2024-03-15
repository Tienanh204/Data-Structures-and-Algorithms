#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n;
int a[1005][1005];
vector<int> v[1005];

int main()
{
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);
		string token;
		while (ss >> token)
		{
			v[i].push_back(stoi(token));
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 1)
			{
				cout << i + 1 << " " << j + 1 << endl;
			}
		}
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": ";
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 1)
			{
				cout << j + 1 << " ";
			}
		}
		cout << endl;
	}
}