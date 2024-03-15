#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int a[100];
int x[100];
int daxet[100];
int n, k;
int sum = 0;

void Try(int i, int pos)
{
	for (int j = pos; j <= n; j++)
	{
		if (daxet[a[j]] == 0)
		{
			x[j] = a[j];
			sum += a[j];
			if (sum == k)
			{
				cout << "[";
				for (int l = 1; l <= i; l++)
				{
					cout << x[l] << " ";
				}
				cout << "] ";
				cout << endl;
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
	cin >> n >> k;
	memset(daxet, 0, sizeof(daxet));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	x[0] = 0;
	Try(1, 1);
}