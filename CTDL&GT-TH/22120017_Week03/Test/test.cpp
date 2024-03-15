#include<iostream>
#include<math.h>
#include<queue>
#include<stack>
using namespace std;

struct NODE
{
	int key;
	NODE* l;
	NODE* r;
};
typedef struct NODE* node;

node createNode(int key)
{
	node newNode = new NODE();
	newNode->key = key;
	newNode->l = NULL;
	newNode->r = NULL;
	return newNode;
}

void Insert(node &pRoot, int x)
{
	node add = createNode(x);
	if (pRoot == NULL)
		pRoot = add;
	else
	{
		if (x<pRoot->key)
		{
			Insert(pRoot->l, x);
		}
		else
		{
			Insert(pRoot->r, x);
		}
	}
}

//Duyet truoc
void Preorder(node pRoot)
{
	if (pRoot != NULL)
	{
		cout << pRoot->key << " ";
		Preorder(pRoot->l);
		Preorder(pRoot->r);
	}
}

void Inorder(node pRoot)
{
	if (pRoot != NULL)
	{
		Inorder(pRoot->l);
		cout << pRoot->key << " ";
		Inorder(pRoot->r);
	}
}

void Postorder(node pRoot)
{
	if (pRoot != NULL)
	{
		Postorder(pRoot->l);
		Postorder(pRoot->r);
		cout << pRoot->key << " ";
	}
}

//Duyet theo muc
void LevelOrder(node pRoot)
{
	if (pRoot == NULL)
		return;
	queue<node> q;
	q.push(pRoot);
	while (!q.empty())
	{
		node tmp = q.front(); q.pop();
		cout << tmp->key << " ";
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

//Duyet xoan oc
void spiral(node pRoot)
{
	stack<node> s1, s2;
	s1.push(pRoot);
	while (!s1.empty() || !s2.empty())
	{
		while (!s1.empty())
		{
			node top = s1.top(); s1.pop();
			cout << top->key << " ";
			if (top->r != NULL)
			{
				s2.push(top->r);
			}
			if (top->l != NULL)
			{
				s2.push(top->l);
			}
		}
		while (!s2.empty())
		{
			node top = s2.top(); s2.pop();
			cout << top->key << " ";
			if (top->l != NULL)
			{
				s1.push(top->l);
			}
			if (top->r != NULL)
			{
				s1.push(top->r);
			}
		}
	}
}

node searchNode(node pRoot, int x)
{
	if (pRoot == NULL)
		return NULL;
	if (pRoot->key == x)
		return pRoot;
	if (x < pRoot->key)
	{
		return searchNode(pRoot->l, x);
	}
	if (x > pRoot->key)
	{
		return searchNode(pRoot->r, x);
	}
}

void remove2Node(node &x, node &y)
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
			remove2Node(tmp, tmp->r);
		}
		delete tmp;
	}
}

//remove node cach 2
node minNode(node root)
{
	node tmp = root;
	while (tmp != NULL && tmp->l != NULL) 
	{
		tmp = tmp->l;
	}
	return tmp;
}

node remove(node root, int x)
{
	if (root == NULL)
		return;
	if (x < root->key)
	{
		remove(root->l, x);
	}
	else if (x > root->key)
	{
		remove(root->r, x);
	}
	else {
		if (root->l == NULL) {
			node tmp = root->r;
			delete root;
			return tmp;
		}
		else if (root->r == NULL) {
			node tmp = root->l;
			delete root;
			return tmp;
		}
		else {
			node tmp = minNode(root);
			root->key = tmp->key;
			root->r = remove(root->r, tmp->key);
		}
	}
}


int main()
{
	node pRoot = new NODE();
	pRoot = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		Insert(pRoot, x);
	}
}