#include<iostream>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	cout << "Chuoi: ";
	string s;
	getline(cin, s);

	set<string> se;
	stringstream ss(s);
	string word;

	while (ss >> word)
	{
		se.insert(word);
	}

	cout << se.size() << endl;
	
	cout << *se.begin() << endl;
	cout << *se.rbegin() << endl;

	return 0;
}