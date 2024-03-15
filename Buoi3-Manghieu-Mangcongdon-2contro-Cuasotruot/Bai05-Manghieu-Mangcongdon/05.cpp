#include<iostream>
#include<math.h>
#include<string>

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

	// Xay dung mang hieu D
	int* D = new int[n + 5];

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			D[0] = a[i];

		else
			D[i] = a[i] - a[i - 1];
	}

	//Thuc hien thao tac tren mang hieu
	while (q--)
	{
		cout << "L-R-Q: ";
		int l, r, k;
		cin >> l >> r >> k;

		D[l] += k;
		D[r + 1] -= k;
	}

	//Xay dung mang cong don cua mang hieu(sau all cac thao tac tren)

	long long* F = new long long[n];

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			F[0] = D[i];
		else
		{
			F[i] = F[i - 1] + D[i];
		}
	}

	//In ra mang cong don vua moi xay dung
	for (int i = 0; i < n; i++)
	{
		cout << F[i] << " ";
	}
	cout << endl;

}