#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

struct Node
{
	int data;
	Node* l;
	Node* r;
    
};
typedef struct Node* tree;

void createTree(tree& t)
{
	t = NULL;//Cay chua co phan tu nao
}

//Ham them phan tu x vao cay nhi phan
void insertNode(tree& t, int x)
{
	if (t == NULL)
	{
		Node* p = new Node();//Khoi tao 1 node de them vao cay
		p->data = x;
		p->l = p->r = NULL;
		t = p;//Node p hinh la Node goc <=>  x
	}
	else//Cay co ton tai phan tu
	{
		if (t->data > x)
		{
			insertNode(t->l, x);
		}
		else if (t->data < x)
		{
			insertNode(t->r, x);
		}
	}
}

//Ham xuat du lieu theo NLR
void duyetNLR(tree& t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		duyetNLR(t->l);
		duyetNLR(t->r);
	}
}
//Ham xuat du lieu tho NRL
void duyetNRL(tree& t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		duyetNRL(t->r);
		duyetNRL(t->l);
	}
}
//Ham xuat du lieu theo LNR
void duyetLNR(tree&t)
{
	if (t != NULL)
	{
		duyetLNR(t->l);
		cout << t->data << " ";
		duyetLNR(t->r);
	}
}
//Ham xuat du lieu RNL
void duyetRNL(tree& t)
{
	if (t != NULL)
	{
		duyetRNL(t->r);
		cout << t->data << " ";
		duyetRNL(t->l);
	}
}

//Ham xuat du lieu LRN
void duyetLRN(tree& t)
{
	if (t != NULL)
	{
		duyetLRN(t->l);
		duyetLRN(t->r);
		cout << t->data << " ";
	}
}

//Ham xuat du lieu RLN
void duyetRLN(tree& t)
{
	if (t != NULL)
	{
		duyetRLN(t->r);
		duyetRLN(t->l);
		cout << t->data << " ";
	}
}
//Bai01: Dem so nguyen to trong cay NLR
int prime(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int cntPrime(tree& t,int &cnt)//Ban chat la duyet cay theo cac cach da hoc roi kiem tra tung Node di qua
{
	if (t != NULL)
	{
		if (prime(t->data))
			cnt++;
		cntPrime(t->l,cnt);
		cntPrime(t->r,cnt);
	}
	return cnt;
}

//Kiem 1 node trong cay NLR
Node* findnode(tree& t, int key)
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (t->data > key)
		{
			findnode(t->l, key);
		}
		else if (t->data < key)
		{
			findnode(t->r, key);
		}
		else
		{
			return t;
		}
	}
}

/*
Xuat cac node co 2 con (co cay con trai va cay con phai)
Xuat cac node co 1 con (co cay con trai hoac cay con phai)
Xuat cac node la (khong co cay con trai va cay con phai)
*/
void print2child(tree& t)
{
	if (t != NULL)
	{
		if (t->l != NULL && t->r != NULL)
		{
			cout << t->data << " ";
		}
		print2child(t->l);
		print2child(t->r);
	}
}

void print1child(tree& t)
{
	if (t != NULL)
	{
		if (t->l != NULL || t->r != NULL)
		{
			cout << t->data << " ";
		}
		print2child(t->l);
		print2child(t->r);
	}
}
void print0child(tree& t)
{
	if (t != NULL)
	{
		if (t->l == NULL && t->r == NULL)
		{
			cout << t->data << " ";
		}
		print2child(t->l);
		print2child(t->r);
	}
}


//Bai02: Tim min max trong cay nhi phan theo NLR
//Bai02.1: Tim max
//Cach 1:
int Max = INT_MIN;
int findMax(tree& t)
{
	if (t != NULL)
	{
		if (t->data > Max)
		{
			Max = t->data;
		}
		findMax(t->l);
		findMax(t->r);
	}
	return Max;
}
//Cach 2: Tong quat
//Ta biet duoc rang: Phan tu lon nhat nam ben cay con phai phia ngoai cung ben phai node cha
int findMax1(tree& t)
{
	if (t->r == NULL)
	{
		return t->data;
	}
	return findMax1(t->r);//Duyet den Node cuoi cung nhat ben cay con phai => De tim gia tri lon nhat
}

//Bai02.2
int findMin(tree& t)
{
	if (t->l == NULL)
	{
		return t->data;
	}
	return findMin(t->l);//Duyet den Node cuoi cung nhat ben cay con trai => De tim gia tri nho nhat
}


//Bai03: Xoa mot Node trong cay
//a) Xoa Node co 1 con va Node la

void findNoderemove(tree& x, tree& y)
{
	if (y->l != NULL)
	{
		findNoderemove(x, y->l);//Tim node con trai nhat
	}
	else
	{
		x->data = y->data;//Cap nhap data node can xoa = data node the mang
		x = y;//swap(X,Y) Node X(la Node hung ta se xoa di sau nay) tro den Node the mang => ra khoi ham thi ta se xoa node x
		y = y->r;//Cap nhap lien ket cua node the mang y voi cha cua no
	}
}

void findNoderemove1(tree& x, tree& y)
{
	if (y->r != NULL)
	{
		findNoderemove1(x, y->r);
	}
	else
	{
		x->data = y->data;
		x = y;
		y = y->l;
	}
}


void removeNode(tree& t,int key)
{
	if (t == NULL)
		return;

	if (key < t->data)
	{
		removeNode(t->l, key);
	}
	else if (key > t->data)
	{
		removeNode(t->r, key);
	}
	else//Da tim duoc Node an xoa
	{
		Node *x = t;//Node the mang -> ty se xoa no
		//Xet node co 1 con va node la: duyet cap nhap lien ket giua node cha va node con cua node can xoa
		//Truong hop node 1 con va node la
		if (t->l == NULL)
		{
			t = t->r;
		}
		else if (t->r == NULL)
		{
			t = t->l;
		}
		//Truong hop node co 2 con
		else
		{
			//Cach1: Tim node trai nhat cua cay con phai
			//findNoderemove(x, t->r);

			//Cach2: Tim node phai nhat cua cay con trai
			findNoderemove1(x, t->l);
		}
		delete x;
	}
}


void Menu(tree&t)
{
	while (true)
	{
		cout << "******************* MENU ********************" << endl;
		cout << "1.Nhap du lieu" << endl;
		cout << "2.Xuat du lieu cay NLR" << endl;
		cout << "3.Xuat su lieu cay NRL" << endl;
		cout << "4.Xuat du lieu cay LNR" << endl;
		cout << "5.Dem so nguyen to trong cay" << endl;
		cout << "6.Tim kiem Node trong cay" << endl;
		cout << "7.Tim Max trong cay" << endl;
		cout << "8.Tim Min trong cay" << endl;
		cout << "9.Xoa mot node trong cay" << endl;
		cout << "0.Thoat" << endl;
		cout << "******************* <><> ********************" << endl;

		cout << "Nhap lua chon: ";
		int lc; cin >> lc;
		if (lc < 1)
		{
			cout << "Khong hop le" << endl;
			system("pause");
		}
		else if (lc == 1)
		{
			int x;
			cin >> x;
			insertNode(t, x);
		}
		else if (lc == 2)
		{
			duyetNLR(t);
			system("pause");
		}
		else if (lc == 3)
		{
			duyetNRL(t);
			system("pause");
		}
		else if (lc == 4)
		{
			duyetLNR(t);
			system("pause");
		}
		else if (lc == 5)
		{
			int cnt = 0;
			cntPrime(t, cnt);
			cout << cnt;
			system("pause");
		}
		else if (lc == 6)
		{
			int key; cin >> key;
			Node* p = findnode(t, key);
			if (p==NULL)
			{
				cout << "Not found" << endl;
			}
			else
			{
				cout << "Found" << endl;
			}
			system("pause");
		}
		else if (lc == 7)
		{
			cout << "Max: " << findMax(t) << endl;
			cout << "Max1: " << findMax1(t) << endl;
			system("pause");
		}
		else if (lc == 8)
		{
			cout << "Min: " << findMin(t) << endl;
			system("pause");
		}
		else if (lc == 9)
		{
			int key; cin >> key;
			removeNode(t, key);
			system("pause");
		}
		else if (lc == 10)
		{

			system("pause");
		}
		else
		{
			break;
		}
		system("cls");
	}
}

int main()
{
	tree t;
	createTree(t);
	Menu(t);

	system("pause");
	return 0;
}