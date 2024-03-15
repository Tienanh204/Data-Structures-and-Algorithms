#include<iostream>
using namespace std;

int cnt[10000001] = { 0 };

int main()
{
	cout << "n: ";
	int n; cin >> n;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (cnt[a[i]] >= 1)
		{
			cout << a[i] << " " << cnt[a[i]] << endl;
			cnt[a[i]] = 0;
		}
	}
}