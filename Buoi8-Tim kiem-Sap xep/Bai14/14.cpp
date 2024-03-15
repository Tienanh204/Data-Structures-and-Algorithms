#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int n; cin >> n;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n, greater<int>());
	int nmin = INT_MAX;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		nmin = min(nmin, a[i]-i);
		res += nmin;
		if (nmin == 0)
			break;
	}
	cout << res << endl;
}