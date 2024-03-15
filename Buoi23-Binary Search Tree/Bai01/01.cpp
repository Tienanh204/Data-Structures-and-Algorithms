#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct NODE
{
	int data;
	NODE* l;
	NODE* r;
};


typedef struct NODE* node;

node createNode(int data)
{
	node newNode = new NODE();
	newNode->data = data;
	newNode->l = NULL;
	newNode->r = NULL;
	return newNode;
}
//Cau7
void Insert(node& pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = createNode(x);
	}
	if (x > pRoot->data)
	{
		Insert(pRoot->r, x);
	}
	else if (x < pRoot->data)
	{
		Insert(pRoot->l, x);
	}
}

void spiral(node root)
{
	stack<node> st1, st2;
	st1.push(root);

	while (!st1.empty() || !st2.empty())
	{
		while (!st1.empty())
		{
			node tmp = st1.top(); st1.pop();
			cout << tmp->data << " ";
			if (tmp->r != NULL)
			{
				st2.push(tmp->r);
			}
			if (tmp->l != NULL)
			{
				st2.push(tmp->l);
			}
		}
		while (!st2.empty())
		{
			node tmp = st2.top(); st2.pop();
			cout << tmp->data << " ";
			if (tmp->l != NULL)
			{
				st1.push(tmp->l);
			}
			if (tmp->r != NULL)
			{
				st1.push(tmp->r);
			}
		}
	}
}


int main()
{
	NODE* root = new NODE();
	root = NULL;
	cout << "N: ";
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Node: ";
		int x; cin >> x;
		Insert(root, x);
	}
	cout << endl;
	cout << "Duyet xoan oc: ";
	spiral(root);
}