#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<queue>
#include<set>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m;//Dinh, canh
bool visited[1005];
int a[10005][1005];
vector<int>adj[1005];
vector<pair<int, int>> dscanh;
vector<int> ke[1005];

//THUAT TOAN DFS
//Duyet theo danh sach ke O(V+E)
//Hay dung nhat
void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < m; i++)//Thong nhat goi de quy theo tu tu nho den lon
	{
		sort(adj[i].begin(), adj[i].end());
	}
	memset(visited, false, sizeof(visited));
}

void DFS1(int u)
{
	cout << u << " ";
	visited[u] = true;//Danh dau da tham dinh u
	for(int v : adj[u])
	{
		if (!visited[v])//Neu dinh v chua duyet qua
		{
			DFS1(v);
		}
	}
}

//Duyet theo ma tran ke O(V*V)
void DFS2(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (int i = 1; i <= n; i++)
	{
		if (a[u][i] == 1)
		{
			if (!visited[i])
			{
				DFS2(i);
			}
		}
	}
}

//Duyet theo danh sach canh O(V*E)
void DFS3(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (auto it : dscanh)
	{
		if (it.first == u)//Thang dang xet ke voi u
		{
			if (!visited[it.second])
			{
				DFS3(it.second);
			}
		}
		if (it.second == u)
		{
			if (!visited[it.first])
			{
				DFS3(it.first);
			}
		}
	}
}


//THUAT TOAN BFS
void nhap1()
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

void BFS(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
	
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		cout << x << " ";
		visited[x] = true;
		for (int y : ke[x])
		{
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

//-------------------------------------------------------------------------------------
//Bai Toan Ung Dung Cua DFS va BFS
/*
- Bai toan 1: Dem so thanh phan lieen thong, kiem tra do thi lien thong
- Node: Tinh chat cua do thi lien thong la 2 dinh thuoc cung 1 thnah phan 
  lien thong se co duong di giua chung va nguoc lai
*/
int tplt()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++cnt;
			DFS1(i);//BFS(i)
		}
	}
	return cnt;
}

/*
- Bai toan 2: Tim duong di giua 2 dinh tren do thi
  + Giua 2 dinh tren do thi se khac nhau tuy thuoc vao thuat toan minh dung la BFS hay
  DFS, neu tren do thi khong co trong so thi duong di giua 2 dinh sd thuat toan BFS
  se la duong di ngan nhat. De truy vet duong di ta su dung them mang parent[]
*/

int parent[1005];//Dinh cha cua dinh u
void DFS_2(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			DFS_2(v);
			parent[v] = u;//Luu lai cha cua node hien tai
		}
	}
}

void BFS_2(int u)
{
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		visited[x] = true;
		for (int y : ke[x])
		{
			if (!visited[y])
			{
				parent[y] = x;//Luu lai cha cua node hien tai
				visited[y] = true;
				q.push(y);
			}
		}
	}
}


/*
- Bai toan 3: Dinh tru, canh cau
 a) Dinh tru
 -la dinh loai bo dinh nay va cac canh lien thuoc voi dinh nay se lam tang
 so thanh phan lien thong cua do thi
 -Do phuc tao O(V*(E+V))

 b)Canh cau
 -La nhung canh loai bo no (Chi loai bo canh, khong loai bo 2 dinh) lam tang
 so tplt cua do thi
 -Do phuc tap: O(E*(E+V))
*/

int tplt()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++cnt;
			DFS1(i);//BFS(i)
		}
	}
	return cnt;
}
//Dinh tru
void dinh_tru()
{
	int cc = tplt();// So thanh phan lien thong ban dau;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;//Loai bo dinh i khoi do thi
		if (cc < tplt())//Tuc day la dinh tru
		{
			cout << i << " ";
		}
	}
}

set<int> ke1[1005];
vector<pair<int, int>>dscanh1;
//Canh cau
//*Cach 1: :> khong hay
void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		dscanh1.push_back({ x,y });
		ke1[x].insert(y);
		ke1[y].insert(x);
	}
}

int canhcau()
{
	int cc = tplt();
	int dem = 0;
	for (auto it : dscanh1)
	{
		int x = it.first, y = it.second;
		ke1[x].erase(y);
		ke1[y].erase(x);

		memset(visited, false, sizeof(visited));
		if (cc < tplt())
		{
			++dem;
		}
		ke1[x].insert(y);
		ke1[y].insert(x);
	}
	return dem;
}


int canh_cau()
{
	int cc = tplt();
	int dem = 0;//dem so canh cau
	for (auto it : dscanh1)
	{
		int x = it.first, y = it.second;
		ke1[x].erase(y);
		ke1[y].erase(x);

		memset(visited, false, sizeof(visited));
		if (cc < tplt())
		{
			++dem;
		}
		ke1[x].insert(y);
		ke1[y].insert(x);
	}
	return dem;
}

//*Cah 2: Hay hon, nay la meo
void DFScc(int u, int s, int t)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if ((u == s && v == t) || (u == t && v == s))
		{
			continue;
		}
		if (!visited[v])
		{
			DFScc(v, s, t);
		}
	}
}
int tplt_cc(int s, int t)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			++cnt;
			DFScc(i, s, t);//BFS(i)
		}
	}
	return cnt;
}

int canh_cau1()
{
	int cc = tplt_cc(0,0);
	int dem = 0;
	for (auto it : dscanh1)
	{
		int x = it.first, y = it.second;
		memset(visited, false, sizeof(visited));
		if (cc < tplt_cc(x, y))
		{
			++dem;
		}
	}
	return dem;
}

/*
 - Bai toan 4: Kiem tra chu trinh tren do thi (Kho)
   De kiem tra chu trinh tren do thi ta kiem tra tren do thi co canh nguoc hay khong
*/

int parent1[1005];

bool DFS_CT(int u)
{
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
		{
			parent1[v] = u;
			if (DFS_CT(v))
			{
				return true;
			}
		}
		else if( v != parent[u])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	nhap();
	dinh_tru();
}
