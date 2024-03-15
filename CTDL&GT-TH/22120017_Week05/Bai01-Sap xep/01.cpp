#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int a[1000001];

//   HEAP SORT

//Cach 1: vong lap
void Shift(int a[], int left, int right)
{
	int x, curr, joint;
	curr = left; joint = 2 * curr + 1;

	x = a[curr];

	while (joint <= right)
	{
		if (joint < right)
		{
			if (a[joint] < a[joint + 1]) //Min heap '<' -> '>'
			{
				joint = joint + 1;
			}
		}
		if (a[joint] < x) //Min heap '<' -> '>'
		{
			break;
		}
		a[curr] = a[joint];
		curr = joint;

		joint = 2 * curr + 1;
	}
	a[curr] = x;
}

void CreateHeap(int a[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		Shift(a, i, N - 1);
	}
}

void HeapSort(int a[], int N)
{
	for (int i = N - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		Shift(a, 0, i - 1);
	}
}

//Cach 2: De quy
void heapify(int a[], int i, int n)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int larget = i;
	if (l<n && a[l]>a[larget])
	{
		larget = l;

	}
	if (r<n && a[r]>a[larget])
	{
		larget = r;
	}
	if (larget != i)
	{
		swap(a[i], a[larget]);
		heapify(a, larget, n);
	}
}

void CreaHeap1(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, i, n);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

/*
* Tinh toan do phuc tap:
  + CreateHeap, heapsort: O(nlogn)
  + Shift, heapify: O(logn)
*/

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	CreateHeap(a, n);
	HeapSort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}