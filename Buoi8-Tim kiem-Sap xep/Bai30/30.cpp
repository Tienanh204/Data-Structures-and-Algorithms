#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

int main()
{
    int n,l;
    cin >> n >> l;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    double nmax = max(a[0], l - a[n - 1]);

    for (int i = 1; i < n; i++)
    {
        nmax = max(nmax, (a[i] - a[i-1])/2.0);
    }
    cout << fixed << setprecision(10) << nmax << endl;
}