#include<iostream>
#include<math.h>
#include<time.h>
#include<ctime>
#include<string>
#include<vector>
using namespace std;

int n;
int* a = new int[n];

void selectionSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min_pos])
			{
				min_pos = j;
			}
		}
		swap(a[i], a[min_pos]);
	}
}

void bubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void insertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int pos = i - 1;
		while (pos >= 0 && x < a[pos])
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}


//Merge Sort
void merge(int* a, int l, int m, int r)
{
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);

	int i = 0, j = 0, cnt = l;
	while (i < x.size() && j < y.size())
	{
		if (x[i] <= y[j])
		{
			a[cnt++] = x[i++];
		}
		else
		{
			a[cnt++] = a[j++];
		}
	}
	while (i < x.size())
	{
		a[cnt++] = a[i++];
	}
	while (j < y.size())
	{
		a[cnt++] = a[j++];
	}
}

void mergeSort(int* a, int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}

int partition(int* a, int l, int r)
{
	int x = a[r];
	int i = l - 1;

	for (int j = l; j < r - 1; j++)
	{
		if (a[j] < x)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	i++;
	swap(a[i], a[r]);
	return i;
}

void quickSort(int* a, int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int p = partition(a, l, r);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, r);
}

void heaptify(int* a, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l<n && a[l]>a[largest])
	{
		largest = l;
	}
	if (r<n && a[r]>a[largest])
	{
		largest = r;
	}
	if (largest != 0)
	{
		swap(a[largest],a[i]);
		heaptify(a, n, largest);
	}
}

void heapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heaptify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heaptify(a, i, 0);
	}
}