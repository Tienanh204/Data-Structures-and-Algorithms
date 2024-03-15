#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<queue>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m;
bool visited[10005];
vector<int> ke[1005];
int parent[1005];

void DFS(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			DFS(v);
			parent[v] = u;
		}
	}
}

int main()
{
	memset(visited, false, sizeof(visited));
	int s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(ke[i].begin(), ke[i].end());
	}
	DFS(s);
	if (!visited[t])
	{
		cout << "-1" << endl;
	}
	else
	{
		vector<int> res;
		while (t != s)
		{
			res.push_back(t);
			t = parent[t];
		}
		res.push_back(s);
		reverse(res.begin(), res.end());
		for (int x : res)
		{
			cout << x << " ";
		}
	}
}