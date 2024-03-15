#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	cout << "N-M: ";
	int n, m; cin >> n >> m;

	int** a = new int* [n+1];
	for (int i = 1; i <= n; i++)
	{
		a[i] = new int[m];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}

	//Xay dung mang cong don
	int prefix[10][10];

	memset(prefix, 0, sizeof(prefix));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
		}
	}

	cout << "Q: ";
	int q; cin >> q;

	while (q--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;

		cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << endl;
	}

	delete[] a;
}