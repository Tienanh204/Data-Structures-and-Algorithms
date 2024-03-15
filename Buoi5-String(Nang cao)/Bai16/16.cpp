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
	string name, date;
	getline(cin, name);
	getline(cin, date);

	transform(name.begin(), name.end(), name.begin(), ::tolower);

	int k = name.size();
	int i = 1;
	while (i < k-1)
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
	while (i < k-1)
	{
		if (name[i] != ' ' && name[i - 1] == ' ')
		{
			name[i] -= 32;
		}
		i++;
	}
	cout << name << endl;
	if (date.size() == 10)
	{
		cout << date << endl;
	}
	else
	{
		int Size = date.size();
		string dateTmp;
		int index[3] = { 0 };
		int k = 0;

		for (int i = 0; i < Size; i++)
		{
			if (date[i] == '/')
			{
				index[k++] = i;
			}
		}
		string ngay = date.substr(0, index[0]);
		string thang = date.substr(index[0]+1,index[1]-3);
		string nam = date.substr(index[1]+1);

		if (ngay.size() != 2)
		{
			ngay = '0' + ngay;
		}
		if (thang.size() != 2)
		{
			thang = '0' + thang;
		}
		cout << ngay << "/" << thang << "/" << nam << endl;
	}
}