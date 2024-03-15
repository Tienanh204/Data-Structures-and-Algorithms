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

node createNode(int key)
{
	node newNode = new NODE();
	newNode->key = key;
	newNode->l = NULL;
	newNode->r = NULL;
	newNode->height = 1;
	return newNode;
}

int Height(node N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int getbalance(node pRoot)
{
	if (pRoot == NULL)
		return 0;
	return Height(pRoot->l) - Height(pRoot->r);
}

//Xoay phai
node rightRotate(node y)
{
	node x = y->l;
	node T1 = x->r;

	x->r = y;
	y->l = T1;

	y->height = 1 + max(Height(y->l), Height(y->r));
	x->height = 1 + max(Height(x->l), Height(x->r));

	return x;
}
//Xoay trai
node leftRotate(node x)
{
	node y = x->r;
	node T1 = y->l;

	y->l = x;
	x->r = T1;

	x->height = 1 + max(Height(x->l), Height(x->r));
	y->height = 1 + max(Height(y->l), Height(y->r));

	return y;
}

void Insert(node& pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = createNode(x);
	}
	if (x < pRoot->key)
	{
		Insert(pRoot->l, x);
	}
	if (x > pRoot->key)
	{
		Insert(pRoot->r, x);
	}
	pRoot->height = 1 + max(Height(pRoot->l), Height(pRoot->r));
	int balance = getbalance(pRoot);

	//Lech trai trai
	if (balance > 1 && x < pRoot->l->key)
	{
		pRoot = rightRotate(pRoot);
	}
	//Lech phai phai
	if (balance<-1 && x>pRoot->r->key)
	{
		pRoot = leftRotate(pRoot);
	}
	//Lech trai phai
	if (balance > 1 && x > pRoot->l->key)
	{
		pRoot->l = leftRotate(pRoot->l);
		pRoot = rightRotate(pRoot);
	}
	//Lech phai trai
	if (balance < -1 && x < pRoot->r->key)
	{
		pRoot->r = rightRotate(pRoot->r);
		pRoot = leftRotate(pRoot);
	}
}

void InsertNormal(node pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = createNode(x);
	}
	if (x < pRoot->key)
	{
		Insert(pRoot->l, x);
	}
	if (x > pRoot->key)
	{
		Insert(pRoot->r, x);
	}
	pRoot->height = 1 + max(Height(pRoot->l), Height(pRoot->r));
}

void remove2Node(node& x, node& y)
{
	if (y->l != NULL)
	{
		remove2Node(x, y->l);
	}
	x->key = y->key;
	x = y;
	y = y->r;
}

void removeNode(node pRoot, int x)
{
	if (pRoot == NULL)
		return;
	if (x < pRoot->key)
	{
		removeNode(pRoot->l, x);
	}
	else if (x > pRoot->key)
	{
		removeNode(pRoot->r, x);
	}
	else
	{
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
			remove2Node(tmp, pRoot->r);
		}
		delete tmp;
	}

	pRoot->height = 1 + max(Height(pRoot->l), Height(pRoot->r));
	int balance = getbalance(pRoot);

	//Truong hop L-L
	if (balance > 1 && getbalance(pRoot->l) >= 0)
	{
		pRoot = rightRotate(pRoot);
	}
	//TH R-R
	if (balance < -1 && getbalance(pRoot->r) <= 0)
	{
		pRoot = leftRotate(pRoot);
	}
	//TH L-R
	if (balance > 1 && getbalance(pRoot->l) < 0)
	{
		pRoot->l = leftRotate(pRoot->l);
		pRoot = rightRotate(pRoot);
	}
	//TH R-L
	if (balance < -1 && getbalance(pRoot->r) > 0)
	{
		pRoot->r = rightRotate(pRoot->r);
		pRoot = leftRotate(pRoot);
	}
	
}