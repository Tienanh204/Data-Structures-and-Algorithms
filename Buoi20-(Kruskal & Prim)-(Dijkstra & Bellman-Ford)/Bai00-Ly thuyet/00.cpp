#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

//********** THUAT TOAN TIM CAY KHUNG CUC TIEU **********
//1. Thuat toan Kruskal
struct edge
{
	int x, y, w;
};
int n, m;//Dinh, canh
vector<edge> dscanh;
int parent[10005];
int sz[10005];
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

//2. Thuat toan Prim
vector<pair<int, int>> adj[10005];
bool taken[10005];
int n, m;

void nhap1()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		adj[y].push_back({ x,w });
	}
	memset(taken, false, sizeof(taken));
}

void Prim(int s)
{
	taken[s] = true;// Nap s vao trong cay khung
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
	//vector<pair<int, int>>, greater<pair<int, int> => Xay dung min heap
	for (auto it : adj[s])
	{
		int t = it.first; 
		if (!taken[t])
		{
			Q.push({ it.second, t });
		}
	}
	long long d = 0;
	while (!Q.empty())
	{
		//Lay ra canh ngan nhat
		pair<int, int> e = Q.top(); Q.pop();
		int u = e.second, w = e.first;
		if (!taken[u])
		{
			d += w;
			taken[u] = true;
			for (auto it : adj[u])
			{
				if (!taken[it.first])
				{
					Q.push({ it.second,it.first });
				}
			}
		}
	}
	cout << d << endl;
}


//********** THUAT TOAN TIM DUONG DI NGAN NHAT **********

//1. Thuat toan Dijkstra
void nhap2()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		//adj[y].push_back({ x,w });
		//Neu do thi vo huong thi lam ca 2 dong tren, con do thi co huong chi lam 1 cai
	}
}

void Dijkstra(int s)//Dinh nguon s
{
	vector<int> d(n + 1, 1e9);//Luu chi phi duong di ban dau chi phi la oo
	d[s] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>>Q;
	Q.push({ 0,s });
	while (!Q.empty())
	{
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second, kc = top.first;

		if (kc > d[u])
			continue;

		//Relaxation
		for (auto it : adj[u])
		{
			int v = it.first, w = it.second;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				Q.push({ d[v],v });
			}
		}
	}
	//In ra trong so duong di tu dinh 1 -> dinh i
	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

//2.Thuat toan Ford-Bellman
vector<edge> E;
int d[1005];
void nhap3()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		edge e = { x,y,w };
		E.push_back(e);
	}
}
void BellmanFord(int s)//Dinh nguon
{
	fill(d + 1, d + n + 1, 1e9);
	d[s] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (auto e : E)
		{
			int u = e.x, v = e.y, w = e.w;
			if (d[v] < 1e9)
			{
				d[v] = min(d[v], d[u] + w);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << " ";
	}
}

//3. Thuat toan Floyd Warshall
int Mat[1005][1005];
//Mat[i][j]: Khoang cach ngan nhat tu dinh i->j
void Floyd()
{
	cin >> n;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				Mat[i][j] = min(Mat[i][j], Mat[i][k] + Mat[k][j]);
			}
		}
	}
}

int main()
{
	nhap2();
	Dijkstra(1);
}

//6 9
//1 2 1
//2 3 2
//1 3 3
//2 4 4
//2 5 5
//3 5 7
//4 6 6
//5 6 3
//4 5 4