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
		visited[x] = true;
		for (int y : ke[x])
		{
			if (!visited[y])
			{
				q.push(y);
				parent[y] = x;
				visited[y] = true;
			}
		}
	}
}

int main()
{
	memset(visited, false, sizeof(visited));
	int n, m, s, t; cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(ke[i].begin(), ke[i].end());
	}
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
		for (int x : res)
		{
			cout << x << " ";
		}
	}
}
