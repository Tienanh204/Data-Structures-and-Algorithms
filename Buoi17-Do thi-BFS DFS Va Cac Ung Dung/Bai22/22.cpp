#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<queue>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
bool visited[10005];
vector<int> ke[1005];
int color[1005];
int n, m;
/*
- Trang: 0 (Chua xet)
- Xam: 1 (Dang xet nhung chua xet xong)
- Den: 2 (Da xet xong)
*/
bool DFS(int u)
{
	color[u] = 1;
	for (int v : ke[u])
	{
		if (color[v] == 0)
		{
			if (DFS(v))
				return true;
		}
		else if (color[v] == 1)
		{
			return true;
		}
	}
	color[u] = 2;
	return false;
}

//Kime tra chu trinh cua do thi co hong bang BFS (Kahn)
int degree[1005];
bool Kahn()
{
	for (int i = 1; i <= n; i++)
	{
		for (int x : ke[i])
		{
			degree[x]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}
	int cnt = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		++cnt;
		for (int v : ke[u])
		{
			--degree[v];
			if (degree[v] == 0)
			{
				q.push(v);
			}
		}
	}
	if (cnt != n)
		return true;
	return false;
}

int main()
{
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
	}
	//bool check = false;
	//for (int i = 1; i <= n; i++)
	//{
	//	if (color[i] == 0)
	//	{
	//		if (DFS(i))
	//		{
	//			check = true;
	//			break;
	//		}
	//	}
	//}
	//if (check)
	//{
	//	cout << "1" << endl;
	//}
	//else
	//{
	//	cout << "0" << endl;
	//}

	if (Kahn())
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
}