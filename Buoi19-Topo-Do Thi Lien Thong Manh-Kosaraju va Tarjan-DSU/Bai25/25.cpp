#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
vector<int> ke[10001];
bool visited[10001][10001];
int n, m;
int parent[1005];

int **house;
int dx[4] = {-1,0,0,1};
int dy[4] = { 0,-1,1,0 };

void DFS(int i, int j)
{
	house[i][j] = 1;
	for (int k = 0; k < 4; k++)
	{
		int i1 = dx[k] + i, j1 = dy[k] + j;
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && house[i1][j1]==0)
		{
			DFS(i1, j1);
		}
	}
}

int main()
{
	cin >> n >> m;
	house = new int*[n+1];
	for (int i = 1; i <= n; i++)
	{
		house[i] = new int[m+1];
	}
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string line;
		cin >> line;
		for (int j = 1; j <= line.size(); j++)
		{
			if (line[j-1] == '.')
			{
				house[i][j] = 0;
			}
			if (line[j-1] == '#')
			{
				house[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (house[i][j]==0)
			{
				++cnt;
				DFS(i, j);
			}
		}
	}
	cout << cnt << endl;
}