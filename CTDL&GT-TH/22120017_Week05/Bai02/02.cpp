#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int a[1000001];

// QUICK SORT

//Cach 1: Chon pivot la phan tu cuoi cung
int partition(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j <= r - 1; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	i++;
	swap(a[r], a[i]);
	return i;
}

void quickSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int p = partition(a, l, r);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, r);
}

//Cach 2: Chon pivot la phan tu chinh giua
void QuickSort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int pivot = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < pivot)
		{
			i++;
		}
		while (a[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	QuickSort(a, l, j);
	quickSort(a, i, r);
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quickSort(a, 0, n - 1);
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}