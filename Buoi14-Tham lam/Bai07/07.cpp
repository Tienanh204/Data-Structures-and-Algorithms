#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<cmath>
#include<string>
#include<map>
#include<queue>
using namespace std;

int main()
{
	cout << "N: ";
	int n; cin >> n;
	vector<pair<int, int>> v;
	while (n--)
	{
		int x, y; cin >> x >> y;
		v.push_back({ x,y });
	}
	for (int i = 0; i < v.size()-1; i++)
	{
		int min = i;
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[min].second > v[j].second)
			{
				min = j;
			}
		}
		swap(v[i], v[min]);
	}
	int res = 1;
	int index = 0;

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[index].second < v[i + 1].first)
		{
			index = i + 1;
			res++;
		}
	}
	cout << res << endl;
}