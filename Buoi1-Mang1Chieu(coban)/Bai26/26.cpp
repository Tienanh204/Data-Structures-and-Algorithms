#include<iostream>
#include<math.h>
#include<map>
using namespace std;

int cnt[10000001] = { 0 };

int main()
{
	cout << "N: ";
	int n; cin >> n;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]] ++;
	}

	
	bool check = true;

	for (int i = 0; i < n; i++)
	{
		if (cnt[a[i]] != 1)
		{
			check = false;
			break;
		}
	}

	if (check)
	{
		for (int i = 0; i < 10000001; i++)
		{
			if (cnt[i] = 1)
			{
				cout << i << " " << cnt[i] << endl;
				break;
			}
		}
	}
	else
	{
		int index = 0;
		int res = 0;

		for (int i = 0; i < 10000001; i++)
		{
			if (cnt[i] > res)
			{
				res = cnt[i];
				index = i;
			}
		}
		cout << index << " " << res << endl;
	}

}