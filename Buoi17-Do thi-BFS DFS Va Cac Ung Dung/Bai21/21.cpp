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
int parent[1005];
int n, m;
int check;

bool DFS(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			parent[v] = u;
			if (DFS(v))
				return true;
		}
		else if (v != parent[u])
		{
			return true;
		}
	}
	return false;;
}

bool BFS(int u)
{
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		visited[x] = true;
		for (int y : ke[x])
		{
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
				parent[y] = x;
			}
			if (y != parent[x])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	if (BFS(1))
		cout << "1" << endl;
	else
	{
		cout << "0" << endl;
	}
}