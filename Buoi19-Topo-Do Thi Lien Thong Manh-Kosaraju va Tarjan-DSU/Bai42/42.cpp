#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
using namespace std;
int parent[1005];
int sz[1005];
int n, m;
int max_curr = 1;

void ktao()
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
}

int Find(int u)
{
	if (u == parent[u])
		return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u == v)
		return false;
	if (sz[u] < sz[v])
		swap(u, v);
	parent[v] = u;
	sz[u] += sz[v];
	max_curr = sz[u];
	return true;
}

int main()
{
	cin >> n >> m;
	ktao();
	int tmp = n;
	vector<pair<int,int>> res;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		if (Union(x, y))
		{
			--tmp;
		}
		cout << tmp << " " << max_curr << endl;
	}
}