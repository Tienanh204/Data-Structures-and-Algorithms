#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

//Bai1: Lam tu cay 1->13

struct NODE {
	int key;
	NODE* l;
	NODE* r;
};

typedef struct NODE* node;

//Cau1
node createNode(int data)
{
	node newNode = new NODE();
	newNode->key = data;
	newNode->l = NULL;
	newNode->r = NULL;
	return newNode;
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
void LNR(node pRoot)
{
	if (pRoot == NULL)
		return;
	LNR(pRoot->l);
	cout << pRoot->key << " ";
	LNR(pRoot->r);
}

//Cau4
void LRN(node pRoot)
{
	if (pRoot == NULL)
		return;
	LRN(pRoot->l);
	LRN(pRoot->r);
	cout << pRoot->key << " ";
}


//Cau5: Duyet cay theo chieu rong BFS
void LevelOrder(node pRoot )
{
	if (pRoot == NULL)
		return;
	queue<node> t;
	t.push(pRoot);

	while (!t.empty())
	{
		node tmp = t.front();
		cout << tmp->key << " ";
		t.pop();

		if (tmp->l != NULL)
		{
			t.push(tmp->l);
		}
		if (tmp->r != NULL)
		{
			t.push(tmp->r);
		}
	}
}

//Cau6
node Search(node pRoot, int x)
{
	if (pRoot == NULL)
		return NULL;
	if (x > pRoot->key)
	{
		return Search(pRoot->r, x);
	}
	else if (x < pRoot->key)
	{
		return Search(pRoot->l, x);
	}
	else
	{
		return pRoot;
	}
}

//Cau7
void Insert(node &pRoot, int x)
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


//Cau8
void remove2Node(node &tmp, node &y)
{
	if (y->l != NULL)
	{
		remove2Node(tmp, y->l);
	}
	tmp->key = y->key;
	tmp = y;
	y = y->r;
}

void Remove(node pRoot, int x)
{
	if (pRoot == NULL)
		return;
	if (x > pRoot->key)
	{
		Remove(pRoot->r, x);
	}
	else if (x < pRoot->key)
	{
		Remove(pRoot->l, x);
	}
	else
	{
		node tmp = pRoot;
		if (pRoot->l == NULL)
			pRoot = pRoot->r;
		else if (pRoot->r == NULL)
			pRoot = pRoot->l;
		else
		{
			remove2Node(tmp, pRoot->r);
		}
		delete tmp;
	}
}

//Cau9
node createTree(int a[], int n)
{
	node pRoot = createNode(a[0]);
	for (int i = 1; i < n; i++)
	{
		Insert(pRoot, a[i]);
	}
	return pRoot;
}

//Cau10
void removeTree(node& pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->l != NULL)
	{
		removeTree(pRoot->l);
	}
	else if (pRoot->r != NULL)
	{
		removeTree(pRoot->r);
	}
	delete pRoot;
	pRoot = NULL;
}

//Cau11
int Height(node pRoot)
{
	if (pRoot==NULL)
		return 0;
	return 1 + max(Height(pRoot->l), Height(pRoot->r));
}

//Cau12
int countNode(node pRoot)
{
	if (pRoot == NULL)
		return 0;
	return 1 + countNode(pRoot->l) + countNode(pRoot->r);
}

//Cau13
int sumNode(node pRoot)
{
	if (pRoot == NULL)
		return 0;
	return pRoot->key+sumNode(pRoot->l)+sumNode(pRoot->r);
}


int main()
{
	NODE* pRoot = new NODE();
	pRoot = NULL;

	while (true)
	{
		cout << "********************************** MENU ****************************" << endl;
		cout << "1. Khoi tao 1 Node" << endl;
		cout << "2. Duyet tien thu tu" << endl;
		cout << "3. Duyet trung thu tu" << endl;
		cout << "4. Duyet hau thu tu" << endl;
		cout << "5. Duyet theo muc" << endl;
		cout << "6. Tim va tra ve 1 node co gia tri cho truoc" << endl;
		cout << "7. Them 1 node vao cay" << endl;
		cout << "8. Xoa 1 node " << endl;
		cout << "9. Khoi tao cay voi mang cho truoc" << endl;
		cout << "10. Xoa hoan toan 1 cay tim kiem" << endl;
		cout << "11. Tinh chieu cao cua cay" << endl;
		cout << "12. Dem so Node cua cay" << endl;
		cout << "13. Tinh tong gia tri cua Node trong cay" << endl;
		cout << "********************************* <><> ****************************" << endl;
		cout << "\n\nNhap lua chon: ";
		int lc; cin >> lc;
		int data;

		if (lc == 1)
		{
			cin >> data;
			pRoot = createNode(data);
			cout << "Node khoi tao: " << pRoot->key << endl;
			system("pause");
		}
		else if (lc == 2)
		{
			NLR(pRoot);
			system("pause");
		}
		else if (lc == 3)
		{
			LNR(pRoot);
			system("pause");
		}
		else if (lc == 4)
		{
			LRN(pRoot);
			system("pause");
		}
		else if (lc == 5)
		{
			LevelOrder(pRoot);
			system("pause");
		}
		else if (lc == 6)
		{
			cin >> data;
			node node = Search(pRoot, data);
			if (node == NULL)
			{
				cout << "Not found!" << endl;
			}
			else
			{
				cout << "Node can tim: " << node->key << endl;
			}
			system("pause");
		}
		else if (lc == 7)
		{
			cin >> data;
			Insert(pRoot, data);
			system("pause");
		}
		else if (lc == 8)
		{
			cin >> data;
			Remove(pRoot, data);
			system("pause");
		}
		else if (lc == 9)
		{
			int a[100];
			int n; cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			node newTree = createTree(a, n);
			LRN(newTree);
			system("pause");
		}
		else if (lc == 10)
		{
			removeTree(pRoot);
			system("pause");
		}
		else if (lc == 11)
		{
			cout << "Chieu cao cua cay: " << Height(pRoot) << endl;
			system("pause");
		}
		else if (lc == 12)
		{
			cout << "So node: " << countNode(pRoot) << endl;
			system("pause");
		}
		else if (lc == 13)
		{
			cout << "Tong node trong cay: " << sumNode(pRoot) << endl;
			system("pause");
		}
		system("cls");
	}
}