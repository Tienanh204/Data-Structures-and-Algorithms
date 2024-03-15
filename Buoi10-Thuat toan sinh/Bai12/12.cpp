#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
using namespace std;

int n, k, final = 0;
int a[100];

int main()
{
	cin >> n >> k;
	vector<vector<int>> res;
	vector<int> tmp;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				cout << a[j] << " ";
			}
		}
		cout << endl;
	}
}