#include<iostream>
#include<math.h>
using namespace std;

//Bai06: Tong chia du

int main()
{
	int n;
	cin >> n;
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		res += tmp;
		res %= (10 ^ 9 + 7);
	}
	cout << res << endl;
}