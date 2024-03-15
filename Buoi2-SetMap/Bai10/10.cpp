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
	//set<int> se;
	map<int, int> mp;
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]] = 1;
		//se.insert(a[i]);
	}
	cout << "b[]: ";
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		if (mp[b[i]] == 1)
		{
			mp[b[i]] = 2;
		}
	}

	/*for (int i = 0; i < m; i++)
	{
		if (se.find(b[i]) != se.end())
		{
			cout << b[i] << " ";
		}
	}*/

	for (int i = 0; i < m; i++)
	{
		if (mp[b[i]] == 2)
		{
			cout << b[i] << " ";
		}
	}

}