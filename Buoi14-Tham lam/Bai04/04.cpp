#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<cmath>
#include<string>
#include<queue>
using namespace std;

int main()
{
	cout << "N-K: ";
	int n, k; cin >> n >> k;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int sum1 = 0, sum2 = 0;
	int ans = min(k, n - k);
	for (int i = 0; i < ans; i++)
	{
		sum1 += a[i];
	}
	for (int i = ans; i < n; i++)
	{
		sum2 += a[i];
	}
	cout << abs(sum2 - sum1) << endl;
}