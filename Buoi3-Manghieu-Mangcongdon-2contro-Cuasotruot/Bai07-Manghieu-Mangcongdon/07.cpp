#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	cout << "N-K-Q: ";
	int n, k, q; cin >> n >> k >> q;

	//Xay dung mang hieu
	int* d = new int[200000];
	for (int i = 0; i < 200000; i++)
	{
		d[i] = 0;
	}
	int l, r;

	while (n--)
	{
		cin >> l >> r;
		l--, r--;

		d[l] += 1;
		d[r + 1] -= 1;
	}

	//Xay dung mang cong don cua d de luu so lan truy van( so lan them duong vao tra sua)

	int* f = new int[200000];

	for (int i = 0; i < 200000; i++)
	{
		f[i] = 0;
	}

	for (int i = 0; i < 200000; i++)
	{
		if (i == 0)
			f[i] = d[i];
		else
			f[i] = f[i - 1] + d[i];
	}

	while (q--)
	{
		cin >> l >> r;
		l--; r--;
		int cnt = 0;
		for (int i = l; i <= r; i++)
		{
			if (f[i] >= k)
				cnt++;
		}
		cout << cnt << endl;
	}

	delete[]d;
	delete[]f;
}