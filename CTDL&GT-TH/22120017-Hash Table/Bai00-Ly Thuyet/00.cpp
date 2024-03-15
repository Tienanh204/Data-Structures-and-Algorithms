#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
int a[10000001];
int n;

// XAY DUNG HASH TABLE VA XU LY DUNG DO BANG LINK LIST

struct Node
{
	int key;
	Node* next;
};
typedef struct Node* node;

int hashFunction(int key)
{
	return key % n;
}

void insert(int key, vector<node> &table)
{
	int index = hashFunction(key);
	node newNode = new Node();
	newNode->key = key;
	newNode->next = NULL;

	if (table[index] == NULL)
	{
		table[index] = newNode;
	}
	else
	{
		node tmp = table[index];
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}

void remove(int key, vector<node> &table)
{
	int index = hashFunction(key);
	node curr = table[index];
	node prev = NULL;

	while (curr != NULL && curr->key != key)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << "Not found!" << endl;
		return;
	}
	if (prev == NULL)//Phan tu can xoa nam o dau (table[index])
	{
		table[index] = curr->next;
	}
	else// Phan tu can xoa nam o giua hoac cuoi
	{
		prev->next = curr->next;
	}
	delete curr;
}

node searchNode(int key, vector<node> table)
{
	int index = hashFunction(key);
	node tmp = table[index];
	while (tmp != NULL&&tmp->key!=key)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}

void display(vector<node> table)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] --> ";
		node tmp = table[i];
		while (tmp != NULL)
		{
			cout << tmp->key;
			if (tmp->next != NULL)
			{
				cout << " --> ";
			}
			tmp = tmp->next;
		}
		cout << endl;
	}
}


int main()
{
	cin >> n;
	vector<node> table(n, NULL);// Hash Table;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		insert(x, table);
	}
	display(table);
	remove(15, table);
	display(table);
}
//5
//9 7 15 15 20