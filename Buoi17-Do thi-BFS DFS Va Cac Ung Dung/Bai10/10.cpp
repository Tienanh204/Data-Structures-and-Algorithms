#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m, s;
bool visited[10005];
vector<int> adj[1005];

void DFS(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (int x : adj[u])
	{
		if (!visited[x])
		{
			DFS(x);
		}
	}
}

int main()
{
	memset(visited, false, sizeof(visited));
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 0; i < n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	DFS(s);
}