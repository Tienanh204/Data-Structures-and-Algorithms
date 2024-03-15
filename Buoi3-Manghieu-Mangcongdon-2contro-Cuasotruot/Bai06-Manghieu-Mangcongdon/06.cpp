
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
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int* D = new int[n + 5];
	for (int i = 0; i < n + 5; i++)
		D[i] = 0;

	// Tinh so lan truy van tren moi doan [L,R];
	while (q--)
	{
		cout << "L-R: ";
		int l, r; cin >> l >> r;

		--l, --r;//Do de no cho l,r chay tu 1-> nen ta phai "--" de dua ve chi so mang
		D[l] += 1;
		D[r + 1] -= 1;
	}

	//Mang cong don F luu so lan truy van cua cac phan tu trong mang a
	int* F = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			F[0] = D[i];

		else
			F[i] = F[i - 1] + D[i];
	}

	//Sort giam dan, muc dich dua cac phan tu lon nhat vao doan truy van nhieu nhat
	sort(F, F + n, greater<int>());
	sort(a, a + n, greater<int>());

	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += F[i] * a[i];
	}
	cout << res << endl;
}