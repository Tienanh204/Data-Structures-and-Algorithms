#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
int a[1000001];

// MERGE SORT

//Chuc nang tron 2 day con tang dan
void merge(int a[], int l, int m, int r)
{
	vector<int> x(a + l, a + m + 1);//[l,m]
	vector<int> y(a + m + 1, a + r + 1);//[m+1,r]

	int i = 0, j = 0, cnt = l;
	while (i < x.size() && j < y.size())
	{
		if (x[i] <= y[j])
		{
			a[cnt++] = x[i++];
		}
		else 
		{
			a[cnt++] = y[j++];
		}
	}
	while (i < x.size())
	{
		a[cnt++] = x[i++];
	}
	while (j < y.size())
	{
		a[cnt++] = y[j++];
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}