#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
#define MAXN 1005
vector<int> adj[MAXN];
int parent[MAXN];
bool visited[MAXN];

void nhap()
{
	ifstream fin;
	fin.open("01.txt", ios::in);
	if (!fin)
	{
		cout << "Can't open file" << endl;
		return;
	}
	fin >> n;
	while (!fin.eof())
	{
		int x, y;
		fin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	fin.close();
}

void DFS(int u)
{
	visited[u] = true;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			DFS(v);
			parent[v] = u;
		}
	}
}

int main()
{
	memset(visited, false, sizeof(visited));
	nhap();
	
	int s = 1, t = 3;
	DFS(s);
	vector<int> res;
	while (t != s)
	{
		res.push_back(t);
		t = parent[t];
	}
	res.push_back(s);
	reverse(res.begin(), res.end());
	for (int x : res)
	{
		cout << x << " ";
	}
	cout << endl;
}