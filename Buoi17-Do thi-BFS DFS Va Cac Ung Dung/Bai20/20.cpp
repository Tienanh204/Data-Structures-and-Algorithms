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
vector<pair<int, int>> dscanh;
int n, m;

void DFS(int u, int s, int t)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			if ((u == s && v == t) || (u == t && v == s))
			{
				continue;
			}
			else if(!visited[v])
			{
				DFS(v, s, t);
			}
		}
	}
}

int tplt(int s, int t)
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++dem;
			DFS(i, s, t);
		}
	}
	return dem;
}

void canh_cau()
{
	int cc = tplt(0,0);
	int dem = 0;
	for (auto it : dscanh)
	{
		memset(visited, false, sizeof(visited));
		int x = it.first, y = it.second;
		if (cc < tplt(x, y))
		{
			++dem;
		}
	}
	cout << dem << endl;
}

int main()
{
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		dscanh.push_back({ x,y });
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	canh_cau();
}