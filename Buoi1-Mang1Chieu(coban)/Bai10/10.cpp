#include<iostream>
#include<math.h>
using namespace std;

int ngto(int n)
{
	if (n < 2)
		return 0;

	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	cout << "n: ";
	int n; cin >> n;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bool check = false;

	for (int i = 1; i < n-1; i++)
	{
		int struoc = 0, ssau = 0;

		for (int j = 0; j < i; j++)
		{
			struoc += a[j];
		}
		for (int k = i + 1; k < n; k++)
		{
			ssau += a[k];
		}

		if (ngto(struoc) && ngto(ssau))
		{
			cout << i << " ";
			check = true;
		}

	}
	if (!check)
	{
		cout << "Not found!" << endl;
	}
	
}