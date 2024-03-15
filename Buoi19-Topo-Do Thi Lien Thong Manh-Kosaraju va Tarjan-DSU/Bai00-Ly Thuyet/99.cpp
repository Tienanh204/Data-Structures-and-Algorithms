#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int n, m;
vector<int> ke[1005];
bool visited[1005];
stack<int> topo;

//1. SAP XEP TOPO
//a) Sap xep Topo voi DFS
void nhap1()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
	memset(visited, false, sizeof(visited));
}

void DFS1(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			DFS1(v);
		}
	}
	topo.push(u);//Khi no da duoc tham xong
}

void TopoDFS()//Cai nay cung co the de trong main luon khoi can viet ham rieng
{
	nhap1();
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			DFS1(i);
		}
	}
	while (!topo.empty())
	{
		cout << topo.top() << " ";
		topo.pop();
	}
}
//b) Sap xep Topo voi BFS (Kahn)
int degree[1005];//Luu ban bac vao cua dinh
void nhap2()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		degree[y]++;
	}
}

void Kahn()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}
	vector<int>topo;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		topo.push_back(u);
		for (int v : ke[u])
		{
			degree[v]--;
			if (degree[v] == 0)
			{
				q.push(v);
			}
		}
	}
	if (topo.size() < n)
	{
		cout << "Do thi co chu trinh" << endl;
	}
	else
	{
		for (int x : topo)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}//-> trong ham main() chi can goi 2 ham tren



//2. THANH PHAN LIEN THONG MANH
//a) Thuat toan Kosaraju
vector<int> Ke[100001];
vector<int> t_ke[100001];
stack<int> st;
void nhap3()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		Ke[x].push_back(y);
		t_ke[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void DFS_1(int u)
{
	visited[u] = true;
	for (int v : Ke[u])
	{
		if (!visited[v])
		{
			DFS_1(v);
		}
	}
	st.push(u);
}

void DFS_2(int u)
{
	visited[u] = true;
	cout << u << " ";
	for (int v : t_ke[u])
	{
		if (!visited[v])
		{
			DFS_2(v);
		}
	}
}

void Kosaraju()
{
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			DFS_1(i);
		}
	}
	memset(visited, false, sizeof(visited));
	int scc = 0;
	while (!st.empty())
	{
		int u = st.top(); st.pop();
		if (!visited[u])
		{
			++scc;
			cout << "SCC " << scc << ": ";
			DFS_2(u);
			cout << endl;
		}
	}
}
//b) Thuat toan Tarjan
//Doi voi do thi vo huong
int disc[1005], low[1005];
int timer = 0;
void nhap4()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void DFS4(int u)
{
	disc[u] = low[u] = ++timer;
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			DFS4(v);
			low[u] = min(low[u], low[v]);
		}
		else
		{
			low[u] = min(low[u], disc[v]);
		}
	}
}

void Tarjan()
{
	nhap4();
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			DFS4(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << disc[i] << " " << low[i] << endl;
	}
}

//3.THUAT TOAN DISJOINT SET UNION
int parent[1005];
void ktao()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
}

int Find(int u)
{
	while (u != parent[u])
	{
		u = parent[u];//lan nguoc la de tim dai dien
	}
	return u;
}

bool Union(int u, int v)//Gia su muon gop 2 dinh u,v
{
	u = Find(u);//Tim dai dien cua dinh u
	v = Find(v);//Tim dai dien cua dinh v
	if (u == v)//u,v thuoc cung 1 tap hop nen khong the gop
	{
		return false;
	}
	else
	{
		if (u < v)
			parent[v] = u;
		else
			parent[u] = v;
		return true;
	}
}

int main()
{
	ktao();
	cout << Union(6, 7) << endl;
	cout << Union(5, 6) << endl;
	cout << Union(4, 5) << endl;
	cout << Union(4, 7) << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << ": " << parent[i] << endl;
	}
}