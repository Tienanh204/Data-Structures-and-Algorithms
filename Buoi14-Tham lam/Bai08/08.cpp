#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<cmath>
#include<set>
#include<string>
#include<map>
#include<queue>
using namespace std;

struct job
{
	int id, deadline, profit;
};



int main()
{
	cout << "N: ";
	int n; cin >> n;
	job j[10];
	for (int i = 0; i < n; i++)
	{
		cin >> j[i].id >> j[i].deadline >> j[i].profit;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int k = i + 1; k < n; k++)
		{
			if (j[min].profit < j[k].profit)
			{
				min = k;
			}
		}
		swap(j[min], j[i]);
	}
	set<int> se;
	int prof = 0;
	for (int i = 0; i < n; i++)
	{
		if (se.find(j[i].deadline) == se.end())
		{
			prof += j[i].profit;
			se.insert(j[i].deadline);
		}
	}
	cout << prof << endl;
}