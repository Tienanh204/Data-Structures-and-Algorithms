#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
		{
			cnt += 1;
		}
	}
	cout << cnt << endl;
}
