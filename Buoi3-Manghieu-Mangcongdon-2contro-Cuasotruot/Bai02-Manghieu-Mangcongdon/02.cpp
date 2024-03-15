#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	cout << "N-Q: ";
	int n, q; cin >> n >> q;

	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	//Xay dung mang cong don
	long long* f = new long long[n+5];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			f[i] = a[i];
		else
			f[i] = f[i - 1] + a[i];
	}

	for (int i = 0; i < n; i++)
		cout << f[i] << " ";

	//Xu ly ycbt
	while (q--)
	{
		cout << "[L,R]: ";
		int l, r; cin >> l >> r;
		if (l == 0)
		{
			cout << f[r] << endl;
		}
		else
		{
			cout << f[r] - f[l - 1] << endl;
		}
	}
}