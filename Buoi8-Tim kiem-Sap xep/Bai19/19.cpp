#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int x;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(a + i + 1, a + n, k - a[i] );
        cnt += (a + n) - it;
    }
    cout <<cnt<< endl;
}