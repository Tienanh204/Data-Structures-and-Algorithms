#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m;
int a[10000001];
vector<int>v[10];

int main()
{
	cout << "N M: ";
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <=n; i++)
	{
		sort(v[i].begin(), v[i].end());
		cout << i << ": ";
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}