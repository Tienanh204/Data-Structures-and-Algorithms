#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int cnt[10000001] = { 0 };

int first[1000001] = { 0 };

bool cmp1(int a, int b)
{
	if (cnt[a] != cnt[b])
		return cnt[a] > cnt[b];
	return a < b;
}


bool cmp2(int a, int b)
{
	if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
	return first[a] < first[b];
}
int main()
{
	int n; cin >> n;
	int a[100];
	int b[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		cnt[a[i]]++;

		b[i] = a[i];

		if (cnt[a[i]] == 1) first[a[i]] = i;
	}
	sort(a, a + n, cmp1);

	sort(b, b + n, cmp2);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (int x : b)
	{
		cout << x << " ";
	}
}