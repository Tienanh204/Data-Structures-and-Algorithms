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
        se.insert(a[i]);
    }

    int t; cin >> t;

    while (t--)
    {
        int choice; cin >> choice;

        if (choice == 1)
        {
            int x; cin >> x;
            se.insert(x);
        }
        else if (choice == 2)
        {
            int x; cin >> x;
            if (se.find(x) != se.end())
            {
                se.erase(x);
            }
        }
        else if (choice == 3)
        {
            cout << *se.begin() << endl;
        }
        else if (choice == 4)
        {
            cout << *se.rbegin() << endl;
        }
    }
}