#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

struct Node
{
	int key;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};
typedef struct Node* node;
typedef struct List list;

node createNode(int data)
{
	node newNode = new Node();
	newNode->key = data;
	newNode->next = NULL;
	return newNode;
}

void printList(list *& l)
{
	node tmp = l->head;
	while (tmp != NULL)
	{
		cout << tmp->key << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

bool addHead(List*& l, int data)
{
	node add = createNode(data);
	if (l->head == NULL)
	{
		l->head = add;
		l->tail = add;
		return true;
	}
	else
	{
		add->next = l->head;
		l->head = add;
		return true;
	}
	return  false;
}

bool addTail(List*& l, int data)
{
	node add = createNode(data);
	if (l->head == NULL)
	{
		l->head = add;
		l->tail = add;
		return true;
	}
	else
	{
		l->tail->next = add;
		l->tail = add;
		return true;
	}
	return false;
}

void removeHead(List*& l)
{
	if (l->head == NULL)
		return;
	node tmp = l->head;
	l->head = l->head->next;
	delete tmp;
}

void removeTail(List*& l)
{
	if (l->head == NULL)
		return;
	node tmp = l->head;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}

	node remove = tmp->next;
	tmp->next = NULL;
	delete remove;
}

List* reverseList(List* l) {
	node current = l->head;
	node prev = NULL;
	node pNext = NULL;

	while (current != NULL) {
		pNext = current->next;
		current->next = prev;
		prev = current;
		current = pNext;
	}

	l->head = prev;

	return l;
}

int main()
{
	List* l = new List();
	l->head = NULL;
	l->tail = NULL;
	while (true)
	{
		cout << "*************** MENU ****************" << endl;
		cout << "1. Xuat danh sach" << endl;
		cout << "2. Khoi tao 1 node" << endl;
		cout << "3. Them 1 node vao dau" << endl;
		cout << "4. Them 1 node vao cuoi" << endl;
		cout << "5. Xoa 1 node dau tien" << endl;
		cout << "6. Xoa 1 node cuoi cung" << endl;
		cout << "7. Dao nguoc List" << endl;
		cout << "*************** <><> ****************" << endl;
		cout << "\n\n Nhap lua chon: ";
		int lc; cin >> lc;
		int data;

		if (lc == 1)
		{
			printList(l);
			system("pause");
		}
		else if (lc == 2)
		{
			cin >> data;
			node newNode = createNode(data);
			system("pause");
		}
		else if (lc == 3)
		{
			cin >> data;
			if (addHead(l, data))
			{
				cout << "Da them phan tu: " << data << endl;
			}
			else
			{
				cout << "Phan tu chua duoc them" << endl;
			}
			system("pause");
		}
		else if (lc == 4)
		{
			cin >> data;
			if (addTail(l, data))
			{
				cout << "Da them phan tu: " << data << endl;
			}
			else
			{
				cout << "Phan tu chua duoc them" << endl;
			}
			system("pause");
		}
		else if (lc == 5)
		{
			removeHead(l);
			system("pause");
		}
		else if (lc == 6)
		{
			removeTail(l);
			system("pause");
		}
		system("cls");
	}
}