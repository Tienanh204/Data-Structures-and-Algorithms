#include<iostream>
#include<string>
using namespace std;

int n, final = 0;
int a[100];

void ktao()
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = 0;
	}
}

void sinh()
{
	int i = n;
	while (i >= 1 && a[i] == 1)
	{
		a[i] = 0;
		i--;
	}
	if (i == 0)
		final = 1;
	else
		a[i] = 1;
}

int main()
{
	ktao();
	cin >> n;
	while (!final)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				cout << "B";
			}
			else
			{
				cout << "A";
			}
		}
		cout << endl;
		sinh();
	}
}