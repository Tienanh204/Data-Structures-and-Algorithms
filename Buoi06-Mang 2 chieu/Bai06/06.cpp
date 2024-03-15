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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}
	}

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		swap(a[i][j], a[i][n - i - 1]);
		j++;
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