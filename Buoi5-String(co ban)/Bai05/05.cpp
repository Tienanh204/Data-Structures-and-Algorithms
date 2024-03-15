#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

int main()
{
	string s; cin >> s;
	int n = s.size();
	int cnt = 0;
	string res;

	cnt = n % 3;
	if (cnt == 0) cnt = 3;

	for (int i = 0; i < n; i++)
	{
		res += s[i];
		if (i + 1 == cnt && i + 1 != n)
		{
			res += ",";
			cnt += 3;
		}
	}
	cout << res << endl;
}