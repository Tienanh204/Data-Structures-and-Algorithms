#include<iostream>
#include<queue>
#include<stack>
using namespace std;
vector<int> ke[10001];
bool visited[10001];
int color[10001];
int n, m;
void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
}
//DFS
bool DFS(int u)
{
	color[u] = 1;
	for (int v : ke[u])
	{
		if (color[v] == 0)
		{
			if (DFS(v))
				return true;
		}
		else if(color[v]==1)
		{
			return true;
		}
	}
	color[u] = 2;
	return false;
}

//BFS(Kahn)
int degree[1005];
bool Kahn()
{
	for (int i = 1; i <= n; i++)
	{
		for (int x : ke[i])
		{
			degree[x]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}
	int cnt = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		++cnt;
		for (int v : ke[u])
		{
			degree[v] --;
			if (degree[v] == 0)
			{
				q.push(v);
			}
		}
	}
	if (cnt != n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
}