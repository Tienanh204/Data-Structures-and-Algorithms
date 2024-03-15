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
	cout << "N: ";
	int n; cin >> n;
	cout << "A[]: ";
	int a[100], b[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "B[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
		sum %= (int)(1e9 + 7);
	}
	cout << sum << endl;
}