#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
vector<int> ke[10001];
bool visited[10001];
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
	vector<int> res;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			res.push_back(i);
			++cnt;
			DFS(i);
		}
	}
	cout << cnt - 1 << endl;
	for (int i = 1; i < res.size(); i++)
	{
		cout << res[i - 1] << " " << res[i] << endl;
	}
}