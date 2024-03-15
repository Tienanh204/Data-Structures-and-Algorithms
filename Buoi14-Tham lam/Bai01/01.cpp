#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<concurrent_priority_queue.h>
using namespace std;

int main()
{
	cout << "N: ";
	int n; cin >> n;
	int cnt = 0;
	if (n >= 1000)
	{
		cnt += n / 1000;
		n = n % 1000;
	}
	if (n >= 500)
	{
		cnt += n / 500;
		n = n % 500;
	}
	if (n >= 200)
	{
		cnt += n / 200;
		n = n % 200;
	}
	if (n >= 100)
	{
		cnt += n / 100;
		n = n % 100;
	}

	if (n >= 50)
	{
		cnt += n / 50;
		n = n % 50;
	}
	if (n >= 20)
	{
		cnt += n / 20;
		n = n % 20;
	}
	if (n >= 10)
	{
		cnt += n / 10;
		n = n % 10;
	}
	if (n >= 5)
	{
		cnt += n / 5;
		n = n % 5;
	}
	if (n >= 2)
	{
		cnt += n / 2;
		n = n % 2;
	}
	if (n >= 1)
	{
		cnt += n / 1;
		n = n % 1;
	}
	cout << cnt << endl;
}