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

//Duyet 8 o chung canh voi o (i,j)
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
void Loang(int i, int j)
{
	a[i][j] = 0; // Danh dau da duyet qua

	for (int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1)
		{
			Loang(i1, j1);
		}
	}
}


int main()
{
	Nhap();
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
			{
				cnt++;
				Loang(i, j);
			}
		}
	}
	cout << cnt << endl;
}

//5 5
//1 1 0 1 1
//1 1 0 1 0
//0 0 0 1 0
//0 1 0 0 1
//1 1 0 0 0