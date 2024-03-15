#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int n; cin >> n;
	int a[100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n,greater<int>());

	int nmin = INT_MAX;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt++;
		nmin = min(nmin - 1, a[i]);
		if (nmin == 0)
		{
			break;
		}
	}
	cout << cnt << endl;
}