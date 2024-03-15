#include<iostream>
#include<math.h>
#include<algorithm>
#include<stack>
#include<cmath>
#include<set>
#include<string>
#include<map>
#include<queue>
using namespace std;

int main()
{
	cout << "N: ";
	int n; cin >> n;
	cout << "a[]: ";
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		pq.push(x);
	}
	int res = 0;
	while (pq.size() >= 2)
	{
		int t1 = pq.top(); pq.pop();
		int t2 = pq.top(); pq.pop();
		pq.push(t1 + t2);
		res += (t1 + t2);
	}
	cout << res << endl;
}