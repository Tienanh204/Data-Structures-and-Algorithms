#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

//Y tuong: Su dung ky thuat duyet cac o lien ke
using namespace std;

int n, m;
int s, t, u, v;
int a[100][100];
int F[100][100];

void Nhap()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
}
int dx[4] = {0,1 };
int dy[4] = {1,0 };

void Loang(int i, int j)
{
	a[i][j] = 2;
	for (int k = 0; k < 2; k++)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1]==1)
		{
			Loang(i1, j1);
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> s >> t >> u >> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	Loang(s - 1, t - 1);
	if(a[u - 1][v - 1] == 2)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

//3 5
//1 1 3 5
//1 1 0 0 1
//0 1 1 1 0
//0 0 0 1 1