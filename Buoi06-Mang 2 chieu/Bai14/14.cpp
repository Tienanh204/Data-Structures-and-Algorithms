#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	int n; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[n];

	int x = 1;
	int h1 = 0, c1 = 0, h2 = n - 1, c2 = n - 1;
	while (h1<=h2 || c1<=c2)
	{
		for (int i = c1; i <= c2; i++)
		{
			a[h1][i] = x;
			x++;
		}
		h1++;
		for (int i = h1; i <= h2; i++)
		{
			a[i][c2] = x;
			x++;
		}
		c2--;
		for (int i = c2; i >= c1; i--)
		{
			a[h2][i] = x;
			x++;
		}
		h2--;
		for (int i = h2; i >= h1; i--)
		{
			a[i][c1] = x;
			x++;
		}
		c1++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) delete[]a[i];
	delete[]a;
}