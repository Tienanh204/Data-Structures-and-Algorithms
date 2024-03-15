#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
long long n;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadCompanyList(string file_name)
{
	ifstream fin;
	fin.open(file_name, ios::in);
	vector<Company> cpn;
	if (!fin)
	{
		cout << "Can't onpen file" << endl;
		return cpn;
	}
	while (!fin.eof())
	{
		Company company;
		getline(fin, company.name, '|');
		getline(fin, company.profit_tax, '|');
		getline(fin, company.address);
		cpn.push_back(company);
	}
	fin.close();
	return cpn;
}

//Cau2
long long mod_pow(long long base, long long exp, long long mod)
{
	long long result = 1;
	base = base % mod;
	while (exp > 0) {
		if (exp % 2 == 1)
			result = (result * base) % mod;
		exp = exp >> 1;
		base = (base * base) % mod;
	}
	return result;
}

long long HashString(string company_name)
{
	long long k = company_name.size();
	string res = "";
	if (k > 20)
	{
		res = company_name.substr(k - 20, 20);
	}
	else
	{
		res = company_name;
	}
	long long index = 0;
	long long p = 31;
	long long MOD = 1000000009;
	for (int i = 0; i < res.size(); i++)
	{
		index = (index % MOD + (res[i] * mod_pow(p, i, MOD)) % MOD) % MOD;
	}
	return index;
}

long long index(string company_name)
{
	return HashString(company_name) % n;
}

//Cau3
Company* CreateHashTable(vector<Company>& list_company)
{
	Company* newCompany = new Company[n];
	for (int i = 0; i < n; i++)
	{
		long long idx = index(list_company[i].name);
		while (!newCompany[idx].address.empty())
		{
			idx = (idx + 1) % n;
		}
		newCompany[idx] = list_company[i];
	}
	return newCompany;
}
//Cau4
void Insert(Company*& hash_table, Company company) {
	long long idx = index(company.name);

	bool table_full = true;
	for (int i = 0; i < n; ++i) {
		if (hash_table[idx].address.empty())
		{
			table_full = false; 
			break;
		}
		idx = (idx + 1) % n;
	}

	if (table_full)
	{
		cout << "Hash table is full" << endl;
	}
	else 
	{
		hash_table[idx] = company;
	}
}


//Cau5
Company* Search(Company* hash_table, string company_name)
{
	long long idx = index(company_name);
	long long originalIndex = idx;
	int cnt = 0;

	while (cnt < n && hash_table[idx].name != company_name)
	{
		idx = (idx + 1) % n;
		cnt++;
		if (idx == originalIndex)
		{
			return NULL;
		}
	}
	if (hash_table[idx].name == company_name)
	{
		return &hash_table[idx];
	}
}

void displayCompany(Company* company)
{
	for (int i = 0; i < n ; i++)
	{
		if(!company[i].address.empty())
		cout << company[i].name << "|" << company[i].profit_tax << "|" << company[i].address << endl;
		cout << "---------------------------------------------------------------------------------------------" << endl;
	}
}

int main()
{
	vector<Company> v = ReadCompanyList("MST.txt");
	n = v.size();
	Company* hashTable = CreateHashTable(v);

	//Cau 4
	Company company;
	string name, profix, address;
	getline(cin, name);
	getline(cin, profix);
	getline(cin, address);
	company.name = name;
	company.profit_tax = profix;
	company.address = address;
	Insert(hashTable, company);
	displayCompany(hashTable);

	//string name;
	//getline(cin, name);
	//Company *company = Search(hashTable, name);
	//if (company == NULL)
	//{
	//	cout << "Not found" << endl;
	//}
	//else
	//{
	//	cout << company->name << "|"
	//		<< company->profit_tax << "|"
	//		<< company->address << endl;
	//}
}