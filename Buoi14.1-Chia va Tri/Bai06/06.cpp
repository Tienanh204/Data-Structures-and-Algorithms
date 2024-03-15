#include<iostream>
#include<math.h>
#include<string>
using namespace std;

long long crossingSum(int a[], int l, int r, int mid)
{
	int sumLeft = 0, maxSumLeft = 0;
	int sumRight = 0, maxSumRight = 0;
	for (int i = mid; i >= l; i--)
	{
		sumLeft += a[i];
		maxSumLeft = max(sumLeft, maxSumLeft);
	}
	for (int i = mid + 1; i <= r; i++)
	{
		sumRight += a[i];
		maxSumRight = max(sumRight, maxSumRight);
	}
	return maxSumLeft + maxSumRight;
}

long long maxSum(int a[], int l, int r)
{
	if (l == r)
		return a[l];
	int mid = (l + r) / 2;
	return max({ maxSum(a,l,mid),maxSum(a,mid + 1,r),
		crossingSum(a,l,r,mid)});
}

int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << maxSum(a, 0, n - 1) << endl;
}