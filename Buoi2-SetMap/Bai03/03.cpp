#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
    cout << "n: ";
    int n; cin >> n;
    int* a = new int[n];
    cout << "a[]: ";
    set<int> se;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        auto it = se.find(a[i]);

        if (it == se.end())
        {
            cout << a[i] << " ";
            se.insert(a[i]);
        }
    }

}