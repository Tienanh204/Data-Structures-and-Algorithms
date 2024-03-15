#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
long long sum = 0;
int a[100];
int x[100];
int daxet[100];

void Try(int i, int pos)
{
	for (int j = pos; j <= n; j++)
	{
		if (daxet[j] == 0)
		{
			x[i] = a[j];
			sum += a[j];
			if (sum == k)
			{
				cout << "[ ";
				for (int l = 1; l <= i; l++)
				{
					cout << x[l] << " ";
				}
				cout << "] ";
			}
			else
			{
				Try(i + 1, j + 1);
			}
			sum -= a[j];
		}
	}
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		memset(daxet, 0, sizeof(daxet));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		x[0] = 0;
		Try(1,1);
	}
}

//1
//5
//50
//5 10 15 20 25
