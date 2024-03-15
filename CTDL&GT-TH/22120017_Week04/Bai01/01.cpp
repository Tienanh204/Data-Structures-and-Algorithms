#include<iostream>
#include<math.h>
#include<string>
#include<queue>
using namespace std;

struct NODE
{
	int key;
	NODE* l;
	NODE* r;
	int height;
};

typedef struct NODE* node;


bool Find(node pRoot, node tmp)
{
	if (pRoot == NULL)
	{
		return false;
	}
	if (pRoot->key > tmp->key)
	{
		return Find(pRoot->l, tmp);
	}
	else if (pRoot->key < tmp->key)
	{
		return Find(pRoot->r, tmp);
	}
	else
	{
		return true;
	}
}

int Height(node N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int getBalance(node pRoot)
{
	if (pRoot == NULL)
		return 0;
	return Height(pRoot->l) - Height(pRoot->r);
}

//Cau1
node createNode(int data)
{
	node newNode = new NODE();
	newNode->key = data;
	newNode->l = NULL;
	newNode->r = NULL;
	newNode->height = 1;
	return newNode;
}

//Cau2
//Xoay Phai
node rightRotate(node y)
{
	//Xoay (Chi la cap nhap cac node)
	node x = y->l;
	node T2 = x->r;

	x->r = y;
	y->l = T2;

	//Cap nhap chieu cao
	y->height = 1 + max(Height(y->l), Height(y->r));
	x->height = 1 + max(Height(x->l), Height(x->r));

	//Tra ve node goc moi
	return x;
}

//Xoay Trai
node leftRotate(node x)
{
	node y = x->r;
	node T2 = y->l;

	y->l = x;
	x->r = T2;

	x->height = 1 + max(Height(x->l), Height(x->r));
	y->height = 1 + max(Height(y->l), Height(y->r));

	return y;
}

//Chen cay AVL
void Insert(node& pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = createNode(x);
	}
	if (pRoot->key < x)
	{
		Insert(pRoot->r, x);
	}
	else if (pRoot->key > x)
	{
		Insert(pRoot->l, x);
	}

	pRoot->height = 1 + max(Height(pRoot->l), Height(pRoot->r));

	int balance = getBalance(pRoot);

	//TH1: Lech trai-trai
	if (balance > 1 && x < pRoot->l->key)
	{
		 pRoot = rightRotate(pRoot);
	}
	//TH2: Lech phai-phai
	if (balance<-1 && x>pRoot->r->key)
	{
		pRoot = leftRotate(pRoot);
	}
	//TH3: Lech trai-phai
	if (balance > 1 && x > pRoot->l->key)
	{
		pRoot->l = leftRotate(pRoot->l);
		pRoot = rightRotate(pRoot);
	}
	//TH4: Lech phai-trai
	if (balance < -1 && x < pRoot->r->key)
	{
		pRoot->r = rightRotate(pRoot->r);
		pRoot = leftRotate(pRoot);
	}
}

//Chen bth
void Insert1(node &pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = createNode(x);
	}
	if (pRoot->key < x)
	{
		Insert(pRoot->r, x);
	}
	else if (pRoot->key > x)
	{
		Insert(pRoot->l, x);
	}
	pRoot->height = 1 + max(Height(pRoot->l), Height(pRoot->r));
}

//Cau3
void remove2Node(node & x, node & y)
{
	if (y->l != NULL)
	{
		remove2Node(x, y->l);
	}
	x->key = y->key;
	x = y;
	y = y->r;
}

void Remove(node &pRoot, int x)
{ 
	if (pRoot == NULL)
		return;
	if (pRoot->key < x)
	{
		Remove(pRoot->r, x);
	}
	else if (pRoot->key > x)
	{
		Remove(pRoot->l, x);
	}
	else//Tim thay node do
	{
		//TH1: Node la Node la hoac Node 1 con
		node tmp = pRoot;
		if (pRoot->l == NULL)
		{
			pRoot = pRoot->r;
		}
		else if (pRoot->r == NULL)
		{
			pRoot = pRoot->l;
		}
		else
		{
			remove2Node(pRoot, pRoot->r);
		}
		delete tmp;
	}

	pRoot->height = 1 + max(Height(pRoot->l), Height(pRoot->r));

	int balance = getBalance(pRoot);

	// Left Left Case 
	if (balance > 1 && getBalance(pRoot->l) >= 0)
		pRoot = rightRotate(pRoot);

	// Left Right Case 
	if (balance > 1 && getBalance(pRoot->l) < 0)
	{
		pRoot->l = leftRotate(pRoot->l);
		pRoot =  rightRotate(pRoot);
	}
	// Right Right Case 
	if (balance < -1 && getBalance(pRoot->r) <= 0)
		pRoot =  leftRotate(pRoot);

	// Right Left Case 
	if (balance < -1 && getBalance(pRoot->r) > 0)
	{
		pRoot->r = rightRotate(pRoot->r);
		pRoot = leftRotate(pRoot);
	}
}

//Cau4
void NLR(node pRoot)
{
	if (pRoot == NULL)
		return;
	cout << pRoot->key << " ";
	NLR(pRoot->l);
	NLR(pRoot->r);
}

//Cau5
void LNR(node pRoot)
{
	if (pRoot == NULL)
		return;
	LNR(pRoot->l);
	cout << pRoot->key << " ";
	LNR(pRoot->r);
}

//Cau6
void LRN(node pRoot)
{
	if (pRoot == NULL)
		return;
	LRN(pRoot->l);
	LRN(pRoot->r);
	cout << pRoot->key << " ";
}

//Cau7
void LevelOrder(node pRoot)
{
	if (pRoot == NULL)
		return;

	queue<node> q;
	q.push(pRoot);

	while (!q.empty())
	{
		node tmp = q.front();
		cout << tmp->key << " ";
		q.pop();

		if (tmp->l != NULL)
		{
			q.push(tmp->l);
		}
		if (tmp->r != NULL)
		{
			q.push(tmp->r);
		}
	}
}

//Cau8
bool isAVL(node t)
{
	if (t == NULL) 	return true;

	if (abs(Height(t->l) - Height(t->r)) > 1)
		return false;

	return isAVL(t->l) && isAVL(t->r);
}

int main()
{
	NODE* pRoot = new NODE();
	pRoot = NULL;

	while (true)
	{
		cout << "********************************** MENU ****************************" << endl;
		cout << "1. Tao 1 node" << endl;
		cout << "2. Them 1 Node vao cay AVL" << endl;
		cout << "3. Xoa 1 Node khoi cay AVL" << endl;
		cout << "4. Duyet tien thu tu (NLR)" << endl;
		cout << "5. Duyet trung thu tu (LNR)" << endl;
		cout << "6. Duyet hau thu tu (LRN)" << endl;
		cout << "7. Duyet theo tang" << endl;
		cout << "8. Kiem tra cay co phai cay AVL khong" << endl;
		cout << "********************************* <><> ****************************" << endl;
		cout << "\n\nNhap lua chon: ";
		int lc; cin >> lc;
		int data;

		if (lc == 1)
		{
			cout << "Node can them: ";
			cin >> data;
			pRoot = createNode(data);
			system("pause");
		}
		else if (lc == 2)
		{
			int a[100];
			cout << "So Node: ";
			cin >> data;
			cout << "a[]: ";
			for (int i = 0; i < data; i++)
			{
				cin >> a[i];
			}
			for (int i = 0; i < data; i++)
			{
				Insert1(pRoot, a[i]);
			}
			system("pause");
		}
		else if (lc == 3)
		{
			cout << "Node xoa: ";
			cin >> data;
			Remove(pRoot, data);
			system("pause");
		}
		else if (lc == 4)
		{
			cout << "NLR: ";
			NLR(pRoot);
			system("pause");
		}
		else if (lc == 5)
		{
			cout << "LNR: ";
			LNR(pRoot);
			system("pause");
		}
		else if (lc == 6)
		{
			cout << "LRN: ";
			LRN(pRoot);
			system("pause");
		}
		else if (lc == 7)
		{
			cout << "Duyet theo tang: ";
			LevelOrder(pRoot);
			system("pause");
		}
		else if (lc == 8)
		{
			if (isAVL(pRoot))
			{
				cout << "La cay AVL" << endl;
			}
			else
			{
				cout << "Khong phai ay AVL" << endl;
			}
			system("pause");
		}
		system("cls");
	}
}