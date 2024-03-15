#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100];
    int b[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];

    }
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(b + i + 1, b + n, b[i]);
        if (it == b + n)
        {
            b[i] = '_';
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (binary_search(b, b + n, a[i])==true)
        {
            cout << a[i] << " ";
        }
        else
        {
            cout << "_" << " ";
        }
    }
}