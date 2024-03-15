#include<iostream>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	cout << "N-K: ";
	int n, k; cin >> n >> k;

	int* a = new int[n];

	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	set<int>se;

	for (int i = 0; i <= n - k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			se.insert(a[i + j]);
		}
		cout << *se.begin() << " " << *se.rbegin() << endl;
		se.clear();
	}
}