#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m;//Dinh, canh
#include<set>
bool a[1005][1005];
vector<int> v[1005];

int main()
{
	memset(a, false, sizeof(a));
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
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << i + 1 << " " << v[i][j] << endl;
		}
	}
}