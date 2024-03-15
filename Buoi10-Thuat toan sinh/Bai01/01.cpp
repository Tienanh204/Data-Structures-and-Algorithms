#include<iostream>
#include<string>
using namespace std;

int n, k, a[100];
bool final = 0;

void ktao()
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
}

//To hop chap k cua n
//void sinh()
//{
//	int i = k;
//
//	while (i >= 1 && a[i] == n - k + i)
//	{
//		i--;
//	}
//	if (i == 0)
//		final = 1;
//	else
//	{
//		a[i]++;
//		for (int j = i + 1; j <= k; j++)
//		{
//			a[j] = a[j - 1] + 1;
//		}
//	}
//}

////Sinh hoan vi
//void sinh()
//{
//	int i = n;
//	while (i >= 1 && a[i] > a[i + 1])
//	{
//		i--;
//	}
//	if (i == 0)
//	{
//		final = 1;
//	}
//	else
//	{
//		int j = n;
//		while (a[i] > a[j]) j--;
//		swap(a[i], a[j]);
//		reverse(a + i + 1, a + n + 1);// Ta cung co the dung sort(a+i+1,a+n+1)
//	}
//}

int main()
{
	cin >> n;
	ktao();
	while (!final)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << a[i];
		}
		cout << endl;
		sinh();
	}
}
