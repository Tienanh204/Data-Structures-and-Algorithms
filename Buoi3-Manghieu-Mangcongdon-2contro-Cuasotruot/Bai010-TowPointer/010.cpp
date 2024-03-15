#include<iostream>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

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

	sort(a, a + n);

	bool check = false;

	int l = 0, r = n - 1;
	
	while (l != r)
	{

		if (a[l] + a[r] < k)
		{
			l++;
		}
		else if (a[l] + a[r] > k)
		{
			r--;
		}
		else if (a[l] + a[r]==k)
		{
			check = true;
			break;
		}
	}
	if (check==true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}