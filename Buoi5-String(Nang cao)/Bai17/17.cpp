#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
	string name;
	getline(cin, name);

	transform(name.begin(), name.end(), name.begin(), ::tolower);

	int k = name.size();
	int i = 1;
	while (i < k - 1)
	{
		if (name[i] == ' ' && name[i + 1] == ' ')
		{
			name.erase(i, 1);
			i--;
		}
		i++;
	}
	i = 1;
	name[0] -= 32;
	while (i < k - 1)
	{
		if (name[i] != ' ' && name[i - 1] == ' ')
		{
			name[i] -= 32;
		}
		i++;
	}

	stringstream ss(name);
	string token;
	string* a = new string[name.size() + 1];

    k = 0;
	while (ss >> token)
	{
		a[k++] = token;
	}
	string newname1, newname2;
	for (int i = 0; i < k; i++)
	{
		if (i != k - 2)
		{
			newname1 += a[i]+' ';
		}
		else if (i == k - 2)
		{
			newname1 += a[i]+", ";
		}
	}
	cout << newname1 << endl;



	newname2 += transform(a[k - 1].begin(), a[k - 1].end(), a[k - 1].begin(), :: toupper);
	newname2 += ", ";

	for (int i = 0; i < k - 1; i++)
	{
		newname2 += a[i] + " ";
	}
	cout << newname2 << endl;
}