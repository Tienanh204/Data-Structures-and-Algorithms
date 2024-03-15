#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

//Y tuong: Su dung ky thuat duyet cac o lien ke
using namespace std;

int n;
int s, t, u, v;
int a[100][100];

void Nhap()
{
	cin >> n;
	cin >> s >> t >> u >> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void Loang(int i, int j)
{
	a[i][j] = 0;
	for (int k = 0; k < 8; k++)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && a[i1][j1] == 1)
		{
			Loang(i1, j1);
		}
	}
}

int main()
{
	Nhap();
	Loang(s - 1, t - 1);
	if (a[u - 1][v - 1] == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}