#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<concurrent_priority_queue.h>
using namespace std;


int main()
{
	cout << "A,B: ";
	string a, b;
	cin >> a >> b;

	string summax1 = "", summin1 = "";
	string summax2 = "", summin2 = "";
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '5')
		{
			summax1 += '6';
		}
		else
		{
			summax1 += a[i];
		}

		if (a[i] == '6')
		{
			summin1 += '5';
		}
		else
		{
			summin1 += a[i];
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == '5')
		{
			summax2 += '6';
		}
		else
		{
			summax2 += b[i];
		}
		if (b[i] == '6')
		{
			summin2 += '5';
		}
		else
		{
			summin2 += b[i];
		}
	}
	cout << stoi(summax1) + stoi(summax2) << " " << stoi(summin1) + stoi(summin2) << endl;
}