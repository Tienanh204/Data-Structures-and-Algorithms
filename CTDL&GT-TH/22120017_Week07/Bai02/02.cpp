#include<iostream>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
struct edge
{
	int x, y, w;
};
int n, m;
vector<pair<int, int>>dscanh[1005];
const int INF = (int)1e9;
bool taken[1005];
int parent[1005];
int dist[1005];

//Thuat toan Prim
void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		dscanh[x].push_back({ y,w });
	}
	memset(taken, false, sizeof(taken));
	for (int i = 1; i <= n; i++)
	{
		parent[i] = 0;
		dist[i] = INF;
	}
}

void Prim(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>>Q;
	int d = 0;
	long long dem = 0;
	vector<edge> MST;
	taken[s] = true;
	for (auto it : dscanh[s])
	{
		if (!taken[it.first])
		{
			Q.push({ it.second,it.first });
		}
	}
	while (!Q.empty())
	{
		pair<int,int> e = Q.top(); Q.pop();
		int u = e.second, w = e.first;
		if (!taken[u])
		{
			taken[u] = true;
			d += w;
			++dem;
			if (u != s)
			{
				MST.push_back({ parent[u], u, w });//Neu muon in theo trong so cong don thi thay w->d
			}
			for (auto it : dscanh[u])
			{
				int v = it.first, weighV = it.second;
				if (!taken[it.first] && weighV <dist[v])
				{
					dist[v] = weighV;
					parent[v] = u;
					Q.push({ weighV,v });
				}
			}
		}
	}
	if (dem == n - 1)
	{
		cout << "Trong so: " << d << endl;
		cout << "Cay khung" << endl;
		for (auto it : MST)
		{
			cout << it.x << " " << it.y << " " << it.w << endl;
		}
	}
	else
		cout << "IMPOSSIBLE" << endl;
}

//Thuat toan Dijkstra

void Dijkstra(int s, int t)
{
	dist[s] = 0;
	vector<edge> MST;
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>>Q;
	Q.push({ 0,s });
	long long d = 0;
	while (!Q.empty())
	{
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second, distU = top.first;
		if (distU > dist[u])
			continue;
		if (s != u)
		{
			MST.push_back({ parent[u], u ,distU });
		}
		if (u == t && parent[t]!=INF)
			break;
		for (auto it : dscanh[u])
		{
			int v = it.first, weightV = it.second;
			if (dist[v] > dist[u] + weightV)
			{
				dist[v] = dist[u] + weightV;
				parent[v] = u;
				Q.push({ dist[v],v });
			}
		}
	}
	if (dist[t] == INF)
	{
		cout << "Khong co duong di" << endl;
	}
	else
	{
		cout << "Trong so: " << d << endl;
		cout << "Duong di" << endl;
		for (auto it : MST)
		{
			cout << it.x << " " << it.y << " " << it.w << endl;
		}
	}
}

int main()
{
	nhap();
	Dijkstra(3,4);
	//Prim(0);
}

/*
Trong so: 6
Cay khung
0 1 1
1 3 2
3 2 1
2 5 1
5 4 1
*/