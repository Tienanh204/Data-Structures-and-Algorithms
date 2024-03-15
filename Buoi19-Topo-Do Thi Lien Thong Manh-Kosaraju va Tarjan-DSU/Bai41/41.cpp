#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

//THUAT TOAN KRUSKAL
struct edge
{
	int x, y, w;
};
int n, m;//Dinh, canh
vector<edge> dscanh;
int parent[10005];
int sz[10005];
//THUAT TOAN PRIM
void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edge e = { x,y,w };
		dscanh.push_back(e);
	}
}

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
	return true;
}

void Kruskal()
{
	vector<edge> MST;
	int d = 0;
	sort(dscanh.begin(), dscanh.end(), [](edge x, edge y)->bool { return x.w < y.w; });
	for (int i = 0; i < m; i++)
	{
		edge e = dscanh[i];
		if (MST.size() == n - 1)
			break;
		if (Union(e.x, e.y))
		{
			MST.push_back(e);
			d += e.w;
		}
	}
	if (MST.size() < n - 1)
	{
		cout << "Do thi khong lien thong" << endl;
	}
	else
	{
		cout << d << endl;
		for (auto e : MST)
		{
			cout << e.x << " " << e.y << " " << e.w << endl;
		}
	}
}

int main()
{
	nhap();
	ktao();
	Kruskal();
}