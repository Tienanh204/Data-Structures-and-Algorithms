#include<iostream>
#include<math.h>
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
	for (int i = 0; i < n ; i++)
	{
		if (a[i] < 0 && a[i + 1] > 0 || (a[i] > 0 && a[i + 1] < 0) ||a[i-1]<0&&a[i+1]>0||a[i-1]>0&&a[i+1]<0)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
}