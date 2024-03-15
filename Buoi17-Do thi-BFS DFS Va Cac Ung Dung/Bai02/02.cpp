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
int a[1005][1005] = { 0 };
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
		string x;
		while (ss >> x)
		{
			v[i].push_back(stoi(x));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <v[i].size(); j++)
		{
			if (a[i+1][v[i][j]] == 0 && a[v[i][j]][i+1] == 0)
			{
				cout << i + 1 << ": ";
				cout << v[i][j] << endl;
				a[i+1][v[i][j]] = 1;
				a[v[i][j]][i+1] = 1;
			}
		}
	}
}