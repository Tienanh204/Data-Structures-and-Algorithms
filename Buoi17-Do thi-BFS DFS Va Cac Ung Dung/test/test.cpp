#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<queue>
#include<set>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m;//Dinh, canh
int a[10005][1005];

vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> dscanh;

void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}
//DFS
//Danh sach ke
void DFS(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			DFS(v);
		}
	}
}

//Ma tran ke
void DFS1(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (int i = 1; i <= n; i++)
	{
		if (a[u][i] == 1)
		{
			if (!visited[i])
			{
				DFS1(i);
			}
		}
	}
}


//BFS
void BFS(int u)
{
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		cout << x << " ";
		visited[x] = true;
		for (int y : adj[x])
		{
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

//Bai toan dem so thanh phan lien thong
int tplt()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			DFS(i);
		}
	}
	return cnt;
}
//Tim duong di giua 2 dinh tren do thi
int parent[1000];
void DFS1(int u)
{
	visited[u] = true;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			DFS1(v);
			parent[v] = u;
		}
	}
}
void BFS1(int u)
{
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		visited[u] = true;
		for (int v : adj[u])
		{
			if (!visited[v])
			{
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
}

//Kiem tra chu trinh
bool DFS2(int u)
{
	visited[u] = true;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			parent[v] = u;
			if (DFS2(v))
			{
				return true;
			}
		}
		else if (v != parent[u])
		{
			return true;
		}
	}
	return false;
}

bool BFS2(int u)
{
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		visited[u] = true;
		for (int v : adj[u])
		{
			if (!visited[v])
			{
				parent[v] = u;
				q.push(v);
				visited[v] = true;
			}
			else if (v != parent[u])
			{
				return true;
			}
		}
	}
	return false;
}