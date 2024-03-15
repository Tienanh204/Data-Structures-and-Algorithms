#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
int n, m;
int a[1000][1000];
vector<pair<int, int>>v;


int main()
{
	cout << "N M: ";
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}