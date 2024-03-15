#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

//Y tuong: Su dung ky thuat duyet cac o lien ke
using namespace std;

int n, m;
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

int main()
{
	Nhap();
	for (int i = 1; i < n; i++)
	{
		F[i][0] = F[i - 1][0] + a[i][0];
	}
	for (int j = 1; j < m; j++)
	{
		F[0][j] = F[0][j - 1] + a[0][j];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			F[i][j] = max(F[i - 1][j], F[i][j - 1] + a[i][j]);
		}
	}
	cout << F[n - 1][m - 1] << endl;
}

