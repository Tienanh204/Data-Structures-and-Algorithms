#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;


int n;
int a[100][100];
string s = "";

void Try(int i, int j)
{
	if (i == n && j == n)
	{
		cout << s << endl;
	}
	//Gan nuoc di tiep theo khi ta da o (i,j)
	if (i + 1 <= n && a[i + 1][j] == 1)
	{
		s += "D";
		a[i + 1][j] = 0;//Danh dau da di qua roi
		Try(i + 1, j);
		s.pop_back();//Xoa nuoc di cuoi cung
		a[i + 1][j] = 1;
	}
	if (j + 1 <= n && a[i][j + 1] == 1)
	{
		s += "R";
		a[i][j + 1] = 0;
		Try(i, j + 1);
		s.pop_back();
		a[i][j + 1] = 1;
	}
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
			}
		}
		cout << endl;
		Try(1, 1);
		cout << endl;
	}
}