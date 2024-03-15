#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
using namespace std;

int n, a[100];
int final = 0;
//Bai toan sinh hoan vi

void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}

void sinh()
{
    int i = n;
    while (i >= 1 && a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
        final = 1;
    else
    {
        int j = n;
        while (a[i] > a[j]) j--;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
int main()
{
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    
    stringstream ss(s);
    vector<string> v;
    string token;
    while (ss >> token)
    {
        v.push_back(token);
    }
    sort(v.begin(), v.end());
    ktao();
    while (!final)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                cout << v[0] << " ";
            }
            if (a[i] == 2)
            {
                cout << v[1] <<" ";
            }
            if (a[i] == 3)
            {
                cout << v[2] << " " ;
            }
        }
        cout << endl;
        sinh();
    }
}