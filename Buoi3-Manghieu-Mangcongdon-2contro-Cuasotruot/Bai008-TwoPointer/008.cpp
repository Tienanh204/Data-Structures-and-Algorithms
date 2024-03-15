#include<iostream>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int check(int *a, int l, int r, int k)
{
	set<int> se;

	for (int i = l; i <= r; i++)
	{
		se.insert(a[i]);
	}

	if (se.size() <= k)
		return 1;
	else
		return 0;
}

int dem[10000001] = { 0 };

int main()
{
	cout << "N-K: ";
	int n, k; cin >> n >> k;

	int* a = new int[n];

	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int l = 0;
	int res = 0;

	////Cach 1
	//for (int r = 0; r < n; r++)
	//{
	//	while (check(a, l, r, k) ==0 )
	//	{
	//		l++;
	//	}
	//	res += r - l + 1;
	//}

	//Cach 2
	int cnt = 0;//Dem so luong phan tu khac nhau trong segment
	for (int r = 0; r < n; r++)
	{
		dem[a[r]]++;
		if (dem[a[r]] == 1)
			cnt++;

		while (cnt > k)
		{
			if (dem[a[l]] == 1)
			{
				--cnt;
			}
			dem[a[l]]--; l++;
		}
		res += r - l + 1;
	}

	cout << res << endl;
}

//7 3
//2 6 4 3 6 8 3