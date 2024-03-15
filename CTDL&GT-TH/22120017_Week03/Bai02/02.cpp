#include<iostream>
#include<math.h>
#include<queue>
#include<map>
using namespace std;

//Bai02: Lam tu cau 14->20

struct NODE
{
	int key;
	NODE* l;
	NODE* r;
};

typedef struct NODE* node;

//Ham bo tro
//------------------------------------------------

node createNode(int data)
{
	node newNode = new NODE();
	newNode->key = data;
	newNode->l = NULL;
	newNode->r = NULL;
	return newNode;
}

void NLR(node pRoot)
{
	if (pRoot == NULL)
		return;
	cout << pRoot->key << " ";
	NLR(pRoot->l);
	NLR(pRoot->r);
}

void Insert(node& pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = createNode(x);
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

//---------------------------------------------------

//Cau14
//Tinh chieu cao cua 1 Node cho trươc
int heightNode(node pRoot, int value)
{
	if (pRoot->key == value)
	{
		return 1;
	}
	else if (value < pRoot->key)
	{
		return 1 + heightNode(pRoot->l, value);
	}
	else if (value > pRoot->key)
	{
		return 1 + heightNode(pRoot->r, value);
	}
}
//Cau15
int Level(node root, node p)
{
	return heightNode(root, p->key) - 1;
}
//-----------------------------------------------------------

//Cau16
//Cach 1: Queue
int countLeaf(node pRoot)
{
	if (pRoot == NULL)
		return 0;
	queue<node> n;
	n.push(pRoot);
	int cnt = 0;
	while (!n.empty())
	{
		node tmp = n.front();
		if (tmp->l == NULL && tmp->r == NULL)
		{
			cnt++;
		}
		n.pop();
		if (tmp->l != NULL)
		{
			n.push(tmp->l);
		}
		if (tmp->r != NULL)
		{
			n.push(tmp->r);
		}
	}
	return cnt;
}
//Cach 2: De quy
int countLeaf1(node pRoot)
{
	if (pRoot == NULL)
		return 0;

	int countLeft = countLeaf1(pRoot->l);
	int countRight = countLeaf1(pRoot->r);

	if (countLeft == 0 && countRight == 0)
	{
		return 1;
	}
	return countLeft + countRight;
}

//Cau17
//Cach 1:Queue
int countLess(node pRoot, int x)
{
	if (pRoot == NULL)
		return 0;
	queue<node> n;
	n.push(pRoot);
	int cnt = 0;
	while (!n.empty())
	{
		node tmp = n.front();
		if (tmp->key < x)
		{
			cnt++;
		}
		n.pop();
		if (tmp->l != NULL)
		{
			n.push(tmp->l);
		}
		if (tmp->r != NULL)
		{
			n.push(tmp->r);
		}
	}
	return cnt;
}
//Cach 2: De quy
int countLess1(node pRoot, int x)
{
	if (pRoot == NULL)
		return 0;

	int cnt=0;
	if (pRoot->key < x)
	{
		cnt++;
	}
	cnt+=countLess1(pRoot->r, x);
	cnt+=countLess1(pRoot->l, x);
	return cnt;
}

//Cau18
int countGreater(node pRoot, int x)
{
	if (pRoot == NULL)
		return 0;
	int cnt = 0;
	if (pRoot->key > x)
	{
		cnt++;
	}
	cnt += countGreater(pRoot->l, x);
	cnt += countGreater(pRoot->r, x);
	return cnt;
}

//Cau19
bool isBST(node pRoot, int minValue, int maxValue)
{
	if (pRoot == NULL)
	{
		return true;
	}

	//kiem tra Node hien tai co thuoc khoang (Min,MAx) hay khong
	//Tuc la: Toan bo node ben cay con trai < pRoot va  toan bo Node ben cay con phai > pRoot
	if (pRoot->key < minValue || pRoot->key > maxValue)
	{
		return false;
	}

	return isBST(pRoot->l, minValue, pRoot->key - 1) && isBST(pRoot->r, pRoot->key + 1, maxValue);
}

bool isBSTWrapper(node pRoot)
{
	return isBST(pRoot, INT_MIN, INT_MAX);
}



//Cau20
bool isFullBST(node pRoot)
{
	if (pRoot == NULL)
		return true;
	if ((pRoot->l != NULL && pRoot->r == NULL) || (pRoot->l == NULL && pRoot->r != NULL))
	{
		return false;
	}
	//Kiem tra de quy ho ca 2 nhanh l, r
	bool leftFull = isFullBST(pRoot->l);
	bool rightFull = isFullBST(pRoot->r);

	//Tra ve true neu ca 2 nhanh deu la cay nhi phan day du
	return leftFull && rightFull;
}

int main()
{
	NODE* pRoot = new NODE();
	pRoot = NULL;

	while (true)
	{
		cout << "********************************** MENU ****************************" << endl;
		cout << "1. Them 1 node vao cay" << endl;
		cout << "2. Duyet tien thu tu" << endl;
		cout << "3. Tinh toan chieu cao cua 1 Node voi gia tri cho truoc" << endl;
		cout << "4. Tinh toan tang cua 1 Node cho truoc" << endl;
		cout << "5. Sem so la cua cay" << endl;
		cout << "6. Dem so Node cua cay co key nho hon gia tri cho truoc" << endl;
		cout << "7. Dem so Node cua cay co key lon hon gia tri cho truoc" << endl;
		cout << "8. Xac dinh cay co phai cay nhi phan tim kiem khong" << endl;
		cout << "9. Xac dinh cay co phai cay nhi phan tim kiem day du khong" << endl;
		cout << "********************************* <><> ****************************" << endl;
		cout << "\n\nNhap lua chon: ";
		int lc; cin >> lc;
		int data;
		int n;

		if (lc == 1)
		{
			int a[100];
			cout << "N: ";
			cin >> data;
			cout << "a[]: ";
			for (int i = 0; i < data; i++)
			{
				cin >> a[i];
			}
			for (int i = 0; i < data; i++)
			{
				Insert(pRoot, a[i]);
			}
			system("pause");
		}
		else if (lc == 2)
		{
			NLR(pRoot);
			system("pause");
		}
		else if (lc == 3)
		{
			cout << "Gia tri node: ";
			cin >> data;
			int height = heightNode(pRoot, data);
			if (height == -1)
			{
				cout << "Khong ton tai node co gia tri: " << data << endl;
			}
			else
			{
				cout <<"Chieu cao cua node: "<< height<< endl;
			}
			system("pause");
		}
		else if (lc == 4)
		{
			cout << "Node: ";
			cin >> data;
			node p = createNode(data);
			cout << "Tang cua node: " << Level(pRoot, p) << endl;
			system("pause");
		}
		else if (lc == 5)
		{
			cout << "So la cua cay: " << countLeaf1(pRoot) << endl;
			system("pause");
		}
		else if (lc == 6)
		{
			cout << "Nhap gia tri x: ";
			cin >> data;
			int cnt = countLess1(pRoot, data);
			if (cnt == 0)
			{
				cout << "Khong co node nao thoa ycbt" << endl;
			}
			else
			{
				cout <<"So node co gia tri < "<<data<<": "<<cnt << endl;
			}
			system("pause");
		}
		else if (lc == 7)
		{
			cout << "Nhap gia tri x: ";
			cin >> data;
			int cnt = countGreater(pRoot, data);
			if (cnt == 0)
			{
				cout << "Khong co node nao thoa ycbt" << endl;
			}
			else
			{
				cout << "So node co gia tri < " << data << ": " << cnt << endl;
			}
			system("pause");
		}
		else if (lc == 8)
		{
			bool check1 = isBSTWrapper(pRoot);
			if (check1)
			{
				cout << "La cay nhi phan tim kiem" << endl;
			}
			else
			{
				cout << "Khong la cay nhi phan tim kiem" << endl;
			}
			system("pause");
		}
		else if (lc == 9)
		{
			bool check = isFullBST(pRoot);
			if (check==true)
			{
				cout << "La cay day du" << endl;
			}
			else
			{
				cout << "La cay khong day du" << endl;
			}
			system("pause");
		}
		system("cls");
	}
}