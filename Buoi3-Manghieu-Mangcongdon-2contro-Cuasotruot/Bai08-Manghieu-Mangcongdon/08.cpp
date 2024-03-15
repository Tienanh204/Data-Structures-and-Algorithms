#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include <utility>
#include <tuple>

using namespace std;

int main()
{
	cout << "N-M-K: ";
	int n, m, k; cin >> n >> m >> k;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	//Xay dung mang hieu cua mang a
	int* D = new int[n + 5];

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			D[i] = a[i];
		else
			D[i] = a[i] - a[i - 1];
	}

	vector<tuple<int, int, int>> v;

	while (m--)
	{
		int l, r, d;
		cin >> l >> r >> d;

		v.push_back(make_tuple(l, r, d));
		--l, --r;

		D[l] += d;
		D[r + 1] -= d;
	}


	while (k--)
	{
		int x, y; cin >> x >> y;

		x--, y--;

		for (int i = x; i <= y; i++)
		{
			int l, r, d;

			l = get<0>(v[i]);
			r = get<1>(v[i]);
			d = get<2>(v[i]);

			l--, r--;

			D[l] += d;
			D[r + 1] -= d;
		}
	}

	//Xay dung mang cong don cuoi cung
	int* f = new int[n + 5];

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			f[i] = D[i];
		else
			f[i] = f[i - 1] + D[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << f[i] << " ";
	}
	cout << endl;
}