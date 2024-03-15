#include<iostream>
#include<math.h>
#include<string>
#include<queue>
using namespace std;

struct BSTNode
{
	int key;
	BSTNode* l;
	BSTNode* r;
};

typedef struct BSTNode* bst;


//Cau1
bst createBSTNode(int data)
{
	bst add = new BSTNode();
	add->key = data;
	add->l = NULL;
	add->r = NULL;
	return add;
}

void Insert(bst& root, int x)
{
	if (root == NULL)
	{
		root = createBSTNode(x);
	}
	else if (x < root->key)
	{
		Insert(root->l, x);
	}
	else if (x > root->key)
	{
		Insert(root->r, x);
	}
}

//Cau2
void printByLevel(bst root)
{
	if (root == NULL)
	{
		return;
	}
	queue<bst> Q;
	Q.push(root);

	while (!Q.empty())
	{
		bst tmp = Q.front();
		cout << tmp->key << " ";
		Q.pop();

		if (tmp->l != NULL)
		{
			Q.push(tmp->l);
		}
		if (tmp->r != NULL)
		{
			Q.push(tmp->r);
		}
	}
}

//Cau3
int sumNode(bst root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->key + sumNode(root->l) + sumNode(root->r);
}

//Cau4
int findMax(bst root, int Max, int x) {
	if (root != NULL)
	{
		if (root->key < x)
		{
			Max = max(root->key, Max);
			Max = findMax(root->r, Max, x);
		}
		Max = findMax(root->l, Max, x);
	}
	return Max;
}

bst Search(bst root, int x)
{
	int keyMax = findMax(root, INT_MIN, x);
	if (root == NULL || root->key == keyMax)
	{
		return root;
	}

	while (root != NULL)
	{
		if (root->key == keyMax)
		{
			return root;
		}
		else if (root->key < x)
		{
			root = root->r;
		}
		else if (root->key > x)
		{
			root = root->l;
		}
	}
	return NULL;
}

//Cau5
void Insert1(bst &root, int x)
{
	bst add = createBSTNode(x);
	if (root == NULL)
	{
		root = add;
	}
	else
	{
		bst tmp = root;
		while (true)
		{
			if (x < tmp->key)
			{
				if (tmp->l == NULL)
				{
					tmp->l = add;
					break;
				}
				else
				{
					tmp = tmp->l;
				}
			}
			else if (x > tmp->key)
			{
				if (tmp->r == NULL)
				{
					tmp->r = add;
					break;
				}
				else
				{
					tmp = tmp->r;
				}
			}
		}
	}
}

//Cau6
int Height(bst N)
{
	if (N == NULL)
		return 0;
	return 1 + max(Height(N->l), Height(N->r));
}

int getBalance(bst pRoot)
{
	if (pRoot == NULL)
		return 0;
	return Height(pRoot->l) - Height(pRoot->r);
}

//Xoay Phai
bst rightRotate(bst y)
{
	//Xoay (Chi la cap nhap cac node)
	bst x = y->l;
	bst T2 = x->r;

	x->r = y;
	y->l = T2;

	//Cap nhap chieu cao
	Height(x);
	Height(y);

	//Tra ve node goc moi
	return x;
}

//Xoay Trai
bst leftRotate(bst x)
{
	bst y = x->r;
	bst T2 = y->l;

	y->l = x;
	x->r = T2;

	Height(y);
	Height(x);

	return y;
}

bst convertBSTtoAVL(bst &pRoot)
{
	int balance = getBalance(pRoot);

	// Left Left Case 
	if (balance > 1 && getBalance(pRoot->l) >= 0)
		pRoot = rightRotate(pRoot);

	// Left Right Case 
	if (balance > 1 && getBalance(pRoot->l) < 0)
	{
		pRoot->l = leftRotate(pRoot->l);
		pRoot = rightRotate(pRoot);
	}
	// Right Right Case 
	if (balance < -1 && getBalance(pRoot->r) <= 0)
		pRoot = leftRotate(pRoot);

	// Right Left Case 
	if (balance < -1 && getBalance(pRoot->r) > 0)
	{
		pRoot->r = rightRotate(pRoot->r);
		pRoot = leftRotate(pRoot);
	}
	return pRoot;
}

//Cau7

int cntNumNode(bst root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + cntNumNode(root->l) + cntNumNode(root->r);
}

bool checkComplete(bst root, int index, int numberNodes) {

	// Check if the tree is empty
	if (root == NULL)
		return true;

	if (index >= numberNodes)
		return false;

	return (checkComplete(root->l, 2 * index + 1, numberNodes) && checkComplete(root->r, 2 * index + 2, numberNodes));
}

int main()
{
	bst root = new BSTNode();
	root = NULL;

	cout << "N: ";
	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		Insert1(root, x);
	}
	//cout << "Node: ";
	//int data; cin >> data;
	//bst tmp = Search(root, data);
	//cout <<tmp->key << endl;

	int numNode = cntNumNode(root);
	if (checkComplete(root, 0, numNode))
	{
		cout << "La cay hoan chinh" << endl;
	}
	else
	{
		cout << "Khong la cay hoan chinh" << endl;
	}

}