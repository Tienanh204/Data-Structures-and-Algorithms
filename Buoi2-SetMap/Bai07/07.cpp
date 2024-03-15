#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string s;
    cout << "Chuoi: ";
    set<string> se;
    while (cin>>s)
    {
        se.insert(s);
    }

    cout << se.size() << endl;
    
    auto it = se.begin();
    cout << *it << " ";
    auto it1 = se.end();
    it1--;
    cout << *it1 << endl;
}