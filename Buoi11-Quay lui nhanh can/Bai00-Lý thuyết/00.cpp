#include<iostream>
#include<math.h>
using namespace std;

int x[100], n;
int k;
int daxet[100];


void in()
{
	for (int i = 1; i <= n; i++)
	{
		cout << x[i];
	}
}

//Sinh nhi phan (Quay lui)
void Try(int i)
{
	//Gan cac gia tri co the cho bits thu i
	for (int j = 0; j <= 1; j++)
	{
		x[i] = j;
		if (i == n)//Neu da duyet den bits thu N thi in ra cau hinh cua x
		{
			in();
			cout << endl;
		}
		else
		{
			Try(i + 1);
		}
	}
}

//Sinh to hop nCk (Quay lui)
void Try1(int i)
{
	for (int j = x[i - 1] + 1; j <= n - k + i; j++)
	{
		x[i] = j;
		if (i == k)
		{
			in();
			cout << endl;
		}
		else
		{
			Try1(i + 1);
		}
	}
}

//Sinh hoan vi (Quay lui)
void Try2(int i)
{
	for (int j = 1; j <= n; j++)
	{
		//Kiem tra xem co the gan gia tri cua j cho x[i]
		if (daxet[j] == 0)
		{
			x[i] = j;
			daxet[j] = 1;

			if (i == n)
			{
				in();
				cout << endl;
			}
			else
			{
				Try2(i + 1);
			}
			//<Back track> Bo ghi nhan
			daxet[j] = 0;//Tuc bo ghi nhan de xay dung cac cau hinh khac, phai bo ghi nhan de thang khac no su dung
		}
	}
}

int main()
{
	cin >> n;
	memset(daxet, 0, sizeof(daxet));
	Try2(1);
}
