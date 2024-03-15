#include<iostream>
#include<math.h>
#include<string>
using namespace std;

struct NODE
{
	int key;
	NODE* next;
};
struct List
{
	NODE* head;
};

typedef struct NODE* node;
typedef struct List* list;

node createnode(int key)
{
	node add = new NODE();
	add->key = key;
	add->next = NULL;
	return add;
}

//Cau1
bool addHead(list& l, int data)
{
	node add = createnode(data);
	if (l->head == NULL)
	{
		l->head = add;
		return true;
	}
	else
	{
		add->next = l->head;
		l->head = add;
		return true;
	}
	return false;
}


bool addTail(list& l, int data)
{
	node add = createnode(data);
	if (l->head == NULL)
	{
		l->head = add;
		return true;
	}
	else
	{
		node tmp = l->head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = add;
		return true;
	}
	return false;
}

//Cau2

int cntList(list l)
{
	int cnt = 0;
	node tmp = l->head;
	while (tmp != NULL)
	{
		cnt++;
		tmp = tmp->next;
	}
	return cnt;
}

bool addPost(list& l, int data, int pos)
{
	node add = createnode(data);
	if (l->head == NULL)
	{
		l->head = add;
		return true;
	}
	else
	{
		int n = cntList(l);
		if (pos == 0)
		{
			addHead(l, data);
		}
		else if (pos == n-1)
		{
			addTail(l, data);
		}
		else
		{
			node tmp = l->head;
			for (int i = 0; i < pos - 1; i++)
			{
				tmp = tmp->next;
			}
			add->next = tmp->next;
			tmp->next = add;
		}
		return true;
	}
	return false;
}


void printList(list l)
{
	node tmp = l->head;
	while (tmp!=NULL)
	{
		cout << tmp->key << " ";
		tmp = tmp->next;
	}
}

bool checkLisl(list &l)
{
	if (l->head == NULL || l->head->next == NULL) {
		return true;
	}

	node tmp = l->head;
	while (tmp->next != NULL)
	{
		if (tmp->key > tmp->next->key)
		{
			return false;
		}
	}
	return true;
}

void mergeList(list& L1, list& L2)
{
	list L1 = new List();
	list L2 = new List();
	L1->head = NULL;
	L2->head = NULL;

	list L12 = new List();
	L12->head = NULL;


	int n1 = cntList(L1);
	int n2 = cntList(L2);

	node tmp1 = L1->head;
	node tmp2 = L2->head;

	int i = 0, j = 0;

	bool checkL1 = checkLisl(L1);
	bool checkL2 = checkLisl(L2);

	while (i < n1 && j < n2)
	{
		if (checkL1 && checkL2)
		{
			if (tmp1->key <= tmp2->key)
			{
				addTail(L12, tmp1->key);
				tmp1 = tmp1->next;
				i++;
			}
			else
			{
				addTail(L12, tmp2->key);
				tmp2 = tmp2->next;
				j++;
			}
		}
		else
		{
			if (tmp1->key <= tmp2->key)
			{
				addTail(L12, tmp2->key);
				tmp2 = tmp2->next;
				i++;
			}
			else
			{
				addTail(L12, tmp1->key);
				tmp1 = tmp1->next;
				j++;
			}
		}
	}
	while (i < n1)
	{
		addTail(L12, tmp1->key);
		tmp1 = tmp1->next;
		i++;
	}
	while (j < n2)
	{
		addTail(L12, tmp2->key);
		tmp2 = tmp2->next;
		j++;
	}
	printList(L12);
}


int main()
{
	List* l = new List();
	l->head = NULL;
	cout << "N: ";
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		addTail(l, x);
	}
	//cout << "Vi tri: ";
	//int pos; cin >> pos;
	//cout << "Node: ";
	//int data; cin >> data;
	//addPost(l, data, pos);
	//printList(l);
}