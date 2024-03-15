#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "N-M: ";
	int n, m; cin >> n >> m;

	int* a = new int[n];
	int* b = new int[m];
	set<int> se;
	set<int> set1;
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		set1.insert(a[i]);
	}
	cout << "b[]: ";
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		se.insert(b[i]);
	}

	for (int x : set1)
	{
		if (se.find(x) == se.end())
		{
			cout << x << " ";
		}
	}
}