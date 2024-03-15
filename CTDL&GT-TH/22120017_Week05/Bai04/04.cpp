#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
int a[1000001], n;

//Cau 1
void selectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}

void printArr(int a[], int n)
{
	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//Cau 4: Sap xep theo thu tu gia tri tuyet doi tang dan
void absArr(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[min]) > abs(a[j]))
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}

//Cau5: Sap xep theo quy luat sau
//So duong o dau day giam dan va so am o cuoi day tang dan
void conditionArr(int a[], int n)
{
	int i = 0, j = n-1;
	while (i != j)
	{
		if (a[i] < 0)
		{
			if (a[j] > 0)
			{
				swap(a[i], a[j]);
				i++; j--;
			}
			else
			{
				j--;
			}
		}
		else
		{
			i++;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		if (a[min] > 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[min] < a[j])
				{
					min = j;
			    }
			}
			swap(a[min], a[i]);
		}
		else if(a[min]<0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[min] > a[j])
				{
					min = j;
				}
			}
			swap(a[min], a[i]);
		}
	}
}


int main()
{
	cout << "N: ";
	cin >> n;
	cout << "A[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	conditionArr(a, n);
	printArr(a, n);
}