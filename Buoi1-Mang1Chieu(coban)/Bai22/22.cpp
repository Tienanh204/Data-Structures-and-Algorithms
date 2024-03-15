#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cout << "N-X: ";
	int n,x; cin >> n >> x;
	int* a = new int[n];
	cout << "a[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int index = -1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		for (int i = index; i < n-1; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
	}
	else
	{
		cout << "NOT FOUND" << endl;
	}
	
}