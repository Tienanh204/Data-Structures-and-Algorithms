#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<vector>
using namespace std;

int s, n, cnt = 0;
string chuoi;
int a[100];
int x[100];

void init()
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
}
vector<string>res;
string tmp = "";

void Try(int pos)
{
	for (int j = pos; j < n; j++)
	{
		tmp += chuoi[j];
		if (tmp.size() == s)
		{
			cout << tmp << endl;
		}
		else
		{
			Try(j);
		}
		tmp.pop_back();
	}
}

int main()
{
	cin >> n >> s;
	cin >> chuoi;
	Try(0);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}