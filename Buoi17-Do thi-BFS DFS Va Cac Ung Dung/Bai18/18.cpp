#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<queue>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
bool visited[10005];
vector<int> ke[1005];
int a[1005];
int cnt = 0;
int n, m;

void DFS(int u)
{
	visited[u] = true;
	for(int v : ke[u])
	{
		if (!visited[v])
		{
			a[v] = cnt;
			DFS(v);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++cnt;
			DFS(i);
		}
	}
	int q; cin >> q;
	while (q--)
	{
		int s, t; cin >> s >> t;
		if (a[s] != a[t])
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << "1" << endl;
		}
	}
}