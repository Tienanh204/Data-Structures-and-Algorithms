#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "N: ";
	int n; cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	set<int> se;
	cout << "Q: ";
	int q; cin >> q;

	while (q--)
	{
		int x; cin >> x;

		for (int i = x; i < n; i++)
		{
			se.insert(a[i]);
		}

		cout << se.size()<<" -.- " << endl;
		se.clear();
	}
}