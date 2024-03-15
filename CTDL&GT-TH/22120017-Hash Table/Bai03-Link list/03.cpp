#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
long long n = 200;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

struct Node
{
	Company company;
	Node* next;
};


typedef struct Node* node;

node createNode(Company company)
{
	node newNode = new Node();
	newNode->company = company;
	newNode->next = NULL;
	return newNode;
}

void addTail(node &root ,Company &company)
{
	node add = createNode(company);
	if (root == NULL)
	{
		root = add;
	}
	else
	{
		node tmp = root;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = add;
	}
}

//Cau1
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
		getline(fin, company.name,'|');
		getline(fin, company.profit_tax, '|');
		getline(fin, company.address);
		cpn.push_back(company);
	}
	fin.close();
	return cpn;
}

//Cau2
long long mod_pow(long long base, long long exp, long long mod) {
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

long long HashString(string company_name) {
	string name;
	if (company_name.size() > 20)
		name = company_name.substr(company_name.size() - 20, 20);
	else
		name = company_name;
	long long result = 0, p = 31, m = pow(10, 9) + 9;
	for (long long i = 0; i < name.size(); i++) 
	{
		result = (result + (long long)name[i] * mod_pow(p, i, m)) % m;
	}
	return result;
}

long long index(string company_name)
{
	return HashString(company_name) % n;
}
//Cau3
vector<node> CreateHashTable(vector<Company> list_company)
{
	vector<node> table(n);
	for (int i = 0; i < n; i++)
	{
		table[i] = NULL;
	}
	int j = 1;
	for (int i = 0; i < list_company.size(); i++)
	{
		long long idx = index(list_company[i].name);
		addTail(table[idx], list_company[i]);
	}
	return table;
}

void printCompany(vector<node> table)
{
	for (int i = 0; i < 200; i++) 
	{
		if (!table[i]==NULL)
		{
			node tmp = table[i];
			cout << "Thanh phan 1: ";
			while (tmp != NULL)
			{
				cout << tmp->company.name << " -> ";
					//<< tmp->company.profit_tax << "|"
					//<< tmp->company.address << endl;
				tmp = tmp->next;
			}
			cout << "____________________________________________________" << endl;
		}
	}
}

//Cau4
void Insert(vector<node> &hash_table, Company &company)
{
	addTail(hash_table[index(company.name)], company);
}

//Cau5
Company* Search(vector<node> hash_table, string company_name)
{
	long long idx = index(company_name);
	node tmp = hash_table[idx];
	while (tmp != NULL)
	{
		if (tmp->company.name == company_name)
		{
			return &tmp->company;
		}
		tmp = tmp->next;
	}
	return NULL;
}

//Cau6
Company* remove(vector<node>& hash_table,  string& company_name) {
	long long idx = index(company_name);
	node tmp = hash_table[idx];

	while (tmp->next != NULL) {
		if (tmp->next->company.name == company_name) {
			node to_delete = tmp->next;
			tmp->next = tmp->next->next;
			Company* deleted_company = new Company(to_delete->company);
			delete to_delete;
			return deleted_company;
		}
		tmp = tmp->next;
	}
	return nullptr;
}



int main()
{
	vector<Company> v = ReadCompanyList("MST.txt");
	vector<node> hashTable = CreateHashTable(v);

	////Cau4
	//Company company;
	//string name, profix, address;
	//getline(cin, name);
	//getline(cin, profix);
	//getline(cin, address);
	//company.name = name;
	//company.profit_tax = profix;
	//company.address = address;
	//Insert(hashTable, company);
	//printCompany(hashTable);
	
	////Cau5
	//string company_name;
	//getline(cin, company_name);
	//Company* cpn = Search(hashTable, company_name);
	//if (cpn == NULL)
	//{
	//	cout << "Khong tim thay" << endl;
	//}
	//else
	//{
		//cout << cpn->name << "|"
		//<< cpn->profit_tax << "|"
		//<< cpn->address << endl;
	//}

	//Cau6
	string company_name;
	company_name="";
	getline(cin, company_name);
	Company* cpn1 = remove(hashTable, company_name);
	if (cpn1 == NULL)
	{
		cout << "Khong tim thay" << endl;
	}
	else
	{
		cout << "Da xoa cong ty: ";
		cout << cpn1->name << "|"
			<< cpn1->profit_tax << "|"
			<< cpn1->address << endl;
	}
}







