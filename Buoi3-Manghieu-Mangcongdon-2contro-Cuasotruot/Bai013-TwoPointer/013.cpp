#include<iostream>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s; cin >> s;

	int n = s.size();
	int x, y; cin >> x >> y;

	int cnt2 = 0, cnt8 = 0, ans = 0;
	int l = 0;

	for (int r = 0; r < n; r++)
	{
		if (s[r] == '2')
			cnt2++;
		else
			cnt8++;

		while (cnt2 > x || cnt8 > y)
		{
			if (s[l] == '2')
				cnt2--;
			else
				cnt8--;
			l++;
		}
		ans = max(ans, cnt2 + cnt8);
	}
	cout << ans << endl;
}