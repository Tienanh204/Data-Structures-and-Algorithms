#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int b[100], c[100];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c[i];
	}
	sort(b, b + n,greater<int>());
	sort(c, c + m, greater<int>());

	int i = 0, j = 0;
	int cnt = 0;
	while (i < n && j < m)
	{
		if (b[i] > c[j])
		{
			cnt++;
			j++;
			i++;
		}
		if (b[i] < c[j])
		{
			j++;
		}
	}
	cout << cnt << endl;
}