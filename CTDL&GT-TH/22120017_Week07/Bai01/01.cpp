#include<iostream>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
vector<int> ke[1005];
int parent[1005];
bool visited[1005];
int n, m;

void DFS(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			parent[v] = u;
			DFS(v);
		}
	}
}

void BFS(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
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
		}
	}
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
	int s = 0, t = 5;
	BFS(s);
	if (!visited[t])
	{
		cout << "Khong co duong di" << endl;
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
		for (int i : res)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}