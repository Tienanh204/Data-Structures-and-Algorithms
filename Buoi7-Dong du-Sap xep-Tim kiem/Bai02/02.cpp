#include<iostream>
#include<math.h>
using namespace std;

//Bai07: Tong chia du

int luyThua(int a, int b)
{
	if (b == 0)
		return 1;
	int x= luyThua(a, b / 2);
	if (b % 2 == 0)
		return x * x;
	return x * x * a;
}

int main()
{
	int a, b; cin >> a >> b;

}