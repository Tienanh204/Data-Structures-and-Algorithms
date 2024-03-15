#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	//Cach 1
	//for (int i = 0; i < n; i++)
	//{
	//	auto it = lower_bound(a + i + 1, a + n, a[i] + x);
	//	if (it == a + 1)
	//	{
	//		cout << "-1" << endl;
	//		return 0;
	//	}
	//}
	//cout << "1" << endl;

	//Cach 2:
	sort(a, a + n);
	
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (a[j] - a[i] < x)
		{
			j++;
		}
		else if(a[j] - a[i] > x)
		{
			i++;
		}
		else
		{
			cout << "1" << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}