#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;

	int cnt1[256] = { 0 };
	int cnt2[256] = { 0 };

	for (char x : s1)
	{
		cnt1[x] = 1;
	}
	for (char x : s2)
	{
		cnt2[x] = 1;
	}

	for (int i = 0; i < 256; i++)
	{
		if (cnt1[i] == 1 && cnt2[i] == 1)
		{
			cout << (char)i;
		}
	}
	cout << endl;
	for (int i = 0; i < 256; i++)
	{
		if (cnt1[i] == 1 || cnt2[i] == 1)
		{
			cout << (char)i;
		}
	}
}