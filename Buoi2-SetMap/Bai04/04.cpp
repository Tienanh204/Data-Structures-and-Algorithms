#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "n: ";
	int n;
	cin >> n;
	int* a = new int[n];
	cout << "a[]: ";
	set<int> se;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		se.insert(a[i]);
	}
	int q;
	cout << "q: ";
	cin >> q;
	while (q--)
	{
		int x, y; cin >> x >> y;

		if (x == 1)
		{
			se.insert(y);
		}
		else if (x == 2)
		{
			if (se.find(y) != se.end())
			{
				se.erase(y);
			}
		}
		else if (x == 3)
		{
			if (se.find(y) != se.end())
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		
	}
}