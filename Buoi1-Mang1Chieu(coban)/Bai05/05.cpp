#include<iostream>
using namespace std;

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

	for (int i = 0; i < n; i+=2)
	{
		if (a[i] % 2 == 0)
		{
			cout << a[i] << " ";
			check = true;
		}
	}

	if (!check)
	{
		cout << "NONE" << endl;
	}
}