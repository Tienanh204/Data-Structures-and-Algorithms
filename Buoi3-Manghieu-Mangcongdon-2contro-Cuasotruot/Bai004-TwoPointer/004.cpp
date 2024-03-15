#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	cout << "N-S: ";
	int n, s; cin >> n >> s;

	int* a = new int[n];

	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int l = 0, r = 0;
	int cnt = 0;
	int res = 0;

	//Y tuong duy tri 2 con tro L,R va tinh tong [L,R] so sang voi S sau do cap nhap
	//Noi chung cu duy tri 2 con tro tuy chinh thu hep hay mo rong tong[L,R] sau do so sanh voi S

	//Cach1
	while (l<=r && r<n)
	{
		cnt += a[r];

		if (cnt <= s)
		{
			res = max(res, r - l + 1);
		}
		else
		{
			cnt -= a[l];
			l++;
		}
		r++;
	}

	//Cach 2
	for (int r = 0; r < n; r++)
	{
		cnt += a[r];

		while (cnt > s)
		{
			cnt -= a[l];
			l++;
		}

		res = max(res, r - l + 1);
	}

	cout << res << endl;
}

