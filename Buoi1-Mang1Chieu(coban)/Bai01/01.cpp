#include <iostream>
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

	int chan = 0, le = 0;
	int schan = 0, sle = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			chan++;
			schan += a[i];
		}
		else
		{
			le++;
			sle += a[i];
		}
	}
	cout << le << endl;
	cout << chan << endl;
	cout << schan << endl;
	cout << sle << endl;
}