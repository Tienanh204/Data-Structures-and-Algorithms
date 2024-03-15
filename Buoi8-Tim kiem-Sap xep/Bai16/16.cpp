#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

/*
-Sap xep lich dien (Bai toan kinh dien):
Y tuong: Sap xep theo second tang dan sau do cu noi tiep
bang gio bat dau ca tiep thep ....
*/


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[min].second > v[j].second)
			{
				min = j;
			}
		}
		swap(v[min], v[i]);
	}
	int cnt = 1;
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= v[index].second)
		{
			cnt++;
			index = i;
		}
	}
	cout << cnt << endl;
}