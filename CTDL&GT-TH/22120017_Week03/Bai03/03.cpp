#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

/*
Bai03: Bai lam ve doc ghi file cac so tu nhien trong cay nhi phan tim kiém
*/

struct NODE
{
	int key;
	NODE* l;
	NODE* r;
};
typedef struct NODE* node;

node createNode(int data)
{
	node newNode = new NODE();
	newNode->key = data;
	newNode->l = NULL;
	newNode->r = NULL;
	return newNode;
}

void Insert(node& pRoot, int x)
{
	if (pRoot == NULL)
	{
		node addNode = createNode(x);
		pRoot = addNode;
	}
	if (x > pRoot->key)
	{
		Insert(pRoot->r, x);
	}
	else if (x < pRoot->key)
	{
		Insert(pRoot->l, x);
	}
}

//Cau1

//Doc file cho truoc gia tri n
void readFile(node& pRoot, ifstream& fin)
{
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		fin >> x;
		Insert(pRoot, x);
	}
}

//Doc file khong cho truoc gia tri n
void readFile1(node& pRoot, ifstream& fin)
{
	while (!fin.eof())//Tra ve True neu doc den cuoi file
	{
		string s;
		getline(fin, s,',');
		Insert(pRoot, stoi(s));
	}
}

//Cau2

void NLR(node pRoot)
{
	if (pRoot == NULL)
		return;
	cout << pRoot->key << " ";
	NLR(pRoot->l);
	NLR(pRoot->r);
}

//Cau3
void xuatNodeLa(node pRoot)
{
	if (pRoot != NULL)
	{
		if (pRoot->l == NULL && pRoot->r == NULL)
		{
			cout << pRoot->key << " ";
		}
		xuatNodeLa(pRoot->l);
		xuatNodeLa(pRoot->r);
	}
}
//Cau4
void xuatNode1Con(node pRoot)
{
	if (pRoot != NULL)
	{
		if (pRoot->l == NULL && pRoot->r != NULL || pRoot->l != NULL && pRoot->r == NULL)
		{
			cout << pRoot->key << " ";
		}
		xuatNodeLa(pRoot->l);
		xuatNodeLa(pRoot->r);
	}
}

//Cau5
void xuatNode2Con(node pRoot)
{
	if (pRoot != NULL)
	{
		if (pRoot->l != NULL && pRoot->r != NULL)
		{
			cout << pRoot->key << " ";
		}
		xuatNodeLa(pRoot->l);
		xuatNodeLa(pRoot->r);
	}
}

//Cau6
int findMax(node pRoot)
{
	if (pRoot->r == NULL)
		return pRoot->key;
	findMax(pRoot->r);
}


//Cau7

int cntNode(node root)
{
	if (root == NULL)
		return 0;
	return 1 + cntNode(root->l) + cntNode(root->r);
}

void writeFile(node root, ofstream& fout)
{
	if (root == NULL)
		return;
	fout << root->key << " ";
	writeFile(root->l, fout);
	writeFile(root->r, fout);
}

int main()
{
	NODE* pRoot = new NODE();
	pRoot = NULL;

	while (true)
	{
		cout << "********************************** MENU ****************************" << endl;
		cout << "1. Tao cay tu du lieu trong file" << endl;
		cout << "2. Duyet tien thu tu" << endl;
		cout << "3. Xuat cac node la" << endl;
		cout << "4. Xuat cac node co 1 con" << endl;
		cout << "5. Xuat cac node co 2 con" << endl;
		cout << "6. Tim phan tu lon nhat" << endl;
		cout << "7. Viet du lieu trong cay vao file" << endl;
		cout << "********************************* <><> ****************************" << endl;
		cout << "\n\nNhap lua chon: ";
		int lc; cin >> lc;
		int data;
		if (lc == 1)
		{
			ifstream fin;
			fin.open("input1.txt", ios::in);
			if (!fin)
			{
				cout << "Khong the mo file" << endl;
				return 0;
			}
			readFile1(pRoot, fin);
			fin.close();
			system("pause");
		}
		else if (lc == 2)
		{
			NLR(pRoot);
			system("pause");
		}
		else if (lc == 3)
		{
			cout << "Node la: ";
			xuatNodeLa(pRoot);
			system("pause");
		}
		else if (lc == 4)
		{
			cout << "Node 1 con: ";
			xuatNode1Con(pRoot);
			system("pause");
		}
		else if (lc == 5)
		{
			cout << "Node 2 con: ";
			xuatNode2Con(pRoot);
			system("pause");
		}
		else if (lc == 6)
		{
			cout << "Gia tri lon nhat: " << findMax(pRoot) << endl;
			system("pause");
		}
		else if (lc == 7)
		{
			ofstream fout;
			fout.open("output.txt", ios::out);
			writeFile(pRoot, fout);
			fout.close();
		}
		system("cls");
	}
}