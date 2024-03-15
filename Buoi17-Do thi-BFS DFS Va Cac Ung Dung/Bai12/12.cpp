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

void BFS(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		cout << x << " ";
		visited[x] = true;
		for (int y : ke[x])
		{
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main()
{
	int n, m, s; cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(ke[i].begin(), ke[i].end());
	}
	BFS(s);
}