#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	stringstream ss(s);
	string w;
	int cnt = 0;
	while (ss >> w)
	{
		bool check = true;
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i] < 'A' || w[i]>'Z')
			{
				check=false;
				break;
			}
		}
		if (check)
			cnt++;
	}
	cout << cnt << endl;
}