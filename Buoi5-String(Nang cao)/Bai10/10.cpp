#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<sstream>
#include<set>
#include<unordered_set>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	set<string> se;

	string* a = new string[s.size() + 1];
	stringstream ss(s);
	string token;
	int k = 0;
	while (ss >> token)
	{
		se.insert(token);
		a[k++] = token;
	}
	for (auto it : se)
	{
		cout << it << " ";
	}
	cout << endl;
	se.clear();

	for (int i = 0; i <=k; i++)
	{
		if (se.find(a[i])==se.end())
		{
			cout << a[i] << " ";
			se.insert(a[i]);
		}
	}


}