#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size()-2; i++)
	{
		int index = i;

		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[index] > s[j])
			{
				index = j;
			}
		}
		swap(s[index], s[i]);
	}
	cout << s << endl;
}