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
vector<pair<int,int>> dscanh;

void DFS(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (auto it : dscanh)
	{
		if (it.first==u && !visited[it.second])
		{
			DFS(it.second);
		}
		if (it.second == u && !visited[it.first])
		{
			DFS(it.first);
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
		dscanh.push_back({ x,y });
	}
	DFS(s);
}