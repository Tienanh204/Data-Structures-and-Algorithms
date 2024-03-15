#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

//Y tuong: Su dung ky thuat duyet cac o lien ke
using namespace std;

int n, m;
int a[100][100];

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

//Duyet 8 o xung quang chung dinh voi o (i,j)
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int check(int i, int j)
{
	int nmax = a[i][j];
	for (int k = 0; k < 8; k++)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m)
		{
			if (nmax <= a[i1][j1])
			{
				return 0;
			}
		}
	}
	return 1;
}


int main()
{
	Nhap();
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check(i, j))
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}


