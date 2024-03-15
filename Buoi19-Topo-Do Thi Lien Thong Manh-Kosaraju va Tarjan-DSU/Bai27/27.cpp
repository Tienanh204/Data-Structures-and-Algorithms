#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
vector<int> ke[10001];
bool visited[10001];
int n, m;
int cnt=1;
void DFS(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			++cnt;
			DFS(v);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	int res = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			DFS(i);
		}
		res = max(res, cnt);
		cnt = 1;
	}
	cout << res << endl;
}