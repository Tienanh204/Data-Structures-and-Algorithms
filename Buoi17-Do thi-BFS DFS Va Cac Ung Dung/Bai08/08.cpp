#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n, m;
int a[1005][1005];
vector<int> v[1005];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
			{
				cout << i + 1 << " " << j + 1 <<" "<< a[i][j] << endl;
				a[i][j] = 0;
				a[j][i] = 0;
			}
		}
	}
}