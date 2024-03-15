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
int n, m;

void DFS(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			DFS(v);
		}
	}
}

int tplt()
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++dem;
			DFS(i);
		}
	}
	return dem;
}

void dinh_tru()
{
	int cc = tplt();
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		if (cc < tplt())
		{

			cout << "Dinh tru: " << i << " ";
			++dem;
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
	dinh_tru();
}

