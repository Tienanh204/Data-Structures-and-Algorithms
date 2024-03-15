#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());

	int cnt = 1;
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] - a[i + 1] > k)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
}