#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string token;
    set<string> se;
    string* a = new string[s.size() + 1];

    int k = 0;

    while (ss >> token) {
        se.insert(token);
        a[k++] = token;
    }

    for (auto it : se) {
        cout << it << " ";
    }
    cout << endl;

    for (int i = 0; i < k - 1; i++) {
        int min = i;
        for (int j = i + 1; j < k; j++) {
            if (a[min].size() > a[j].size() || (a[min].size() == a[j].size() && a[min] > a[j])) {
                min = j;
            }
        }
        swap(a[min], a[i]);
    }

    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }

    delete[] a;

    return 0;
}
