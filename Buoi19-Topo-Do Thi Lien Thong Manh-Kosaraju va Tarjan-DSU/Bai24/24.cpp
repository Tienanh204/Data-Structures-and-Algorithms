#include<iostream>
#include<queue>
#include<stack>
using namespace std;
vector<int> ke[10001];
bool visited[10001];
int n, m;
int parent[1005];
/*

 *Tinh chat cua cay:
  + Khong co chu trinh
  + Giua 2 dinh co duy nhat 1 duong di
  + m dinh => n-1 canh
  + Lien thong

=> De chung 1 mot do thi la cay ta chi can chung minh
Cach 1:
 +m=n-1
 +Lien thong
Cach 2:
 +m=n-1
 +Khong co chu trinh

*/
//Cach 1
int cnt = 0;

void DFS(int u)
{
	visited[u] = true;
	cnt++;
	for (int v : ke[u])
	{
		if (!visited[v])
			DFS(v);
	}
}

bool check()
{
	DFS(1);//Neu no la cay no se duyet all cac dinh
	return cnt == n;
}

//Cach 2
int ok = 0;
void dfs(int u)
{
	if (ok)
		return;
	visited[u] = true;
	for (int v : ke[u])
	{
		if (!visited[v])
			dfs(v);
		else if (v != parent[u])
		{
			ok = 1;
			return;
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
	//if (m == n - 1 && check())
	//{
	//	cout << "1" << endl;
	//}
	//else
	//{
	//	cout << "0" << endl;
	//}
	dfs(1);
	if (ok)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
}