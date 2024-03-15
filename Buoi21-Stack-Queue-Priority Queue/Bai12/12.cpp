#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;


int main()
{
	int t; cin >> t;
	queue<pair<int, int>>Q;
	while (t--)
	{
		int x, y; cin >> x >> y;
		Q.push({ x,y });
	}
}