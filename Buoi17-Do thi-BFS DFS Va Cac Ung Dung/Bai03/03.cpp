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
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		v[x].push_back(y);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}