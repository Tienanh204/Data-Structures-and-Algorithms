#include<iostream>
#include<queue>
#include<stack>
using namespace std;
vector<int> ke[10001];
vector<int> t_ke[10001];
bool visited[10001];
stack<int> st;
int n, m;

//Kosaraju
void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		t_ke[y].push_back(x);
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
	st.push(u);
}

void DFS2(int u)
{
	visited[u] = true;
	for (int v : t_ke[u])
	{
		if (!visited[v])
		{
			DFS2(v);
		}
	}
}

int Kosaraju()
{
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			DFS1(i);
		}
	}
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	while (!st.empty())
	{
		int u = st.top(); st.pop();
		if (!visited[u])
		{
			cnt++;
			DFS2(u);
		}
	}
	return cnt;
}

int main()
{
	nhap();
	if (Kosaraju())
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
}