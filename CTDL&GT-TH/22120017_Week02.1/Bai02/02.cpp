#include<iostream>
#include<math.h>
#include<vector>
using namespace std;


struct Node
{
	int key;
	Node* next;
};

struct Stack
{
	Node* top;
};



typedef struct Node* node;
typedef struct Stack stack;

node createNode(int data)
{
	node tmp = new Node();
	tmp->key = data;
	tmp->next = NULL;
	return tmp;
}

void pushStack(stack*& st, int data)
{
	node addHead = createNode(data);
	if (st->top == NULL)
	{
		st->top = addHead;
	}
	else
	{
		addHead->next = st->top;
		st->top = addHead;
	}
}

void popStack(stack*& st)
{
	if (st->top == NULL)
		return;
	node tmp = st->top;
	st->top = st->top->next;
	delete tmp;
}

void printStack(stack*& st)
{
	node tmp = st->top;
	while (tmp != NULL)
	{
		cout << tmp->key << " ";
		tmp = tmp->next;
	}
}

bool Empty(stack*& st)
{
	return st->top == NULL;
}

bool CheckBalance(stack*&st, char* s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			pushStack(st, s[i]);
		}
		else
		{
			if (Empty(st))
			{
				return false;
			}
			else
			{
				popStack(st);
			}
		}
	}
	if (Empty(st))
		return true;
	else
		return false;
}

void DecToBin(stack*&st, int dec)
{
	int n = 0;
	while (dec != 0)
	{
		pushStack(st, dec % 2);
		dec /= 2;
		n++;
	}

	while (16 - n != 0)
	{
		cout << "0";
		n++;
	}
	printStack(st);
}

int main()
{
	Stack* st = new Stack();
	st->top = NULL;
	while (true)
	{
		cout << "*************** MENU ****************" << endl;
		cout << "1. Xuat Stack" << endl;
		cout << "2. Day 1 phan tu vao Stack" << endl;
		cout << "3. Xoa 1 phan tu khoi Stack" << endl;
		cout << "4. Kiem tra dau ngoac hop le" << endl;
		cout << "*************** <><> ****************" << endl;
		cout << "\n\nNhap lua chon: ";
		int lc; cin >> lc;
		int data;

		if (lc == 1)
		{
			printStack(st);
			system("pause");
		}
		else if (lc == 2)
		{
			cin >> data;
			pushStack(st, data);
			system("pause");
		}
		else if (lc == 3)
		{
			popStack(st);
			system("pause");
		}
		else if (lc == 4)
		{
			char* s = new char[100];
			cin.ignore();
			cin.getline(s, 80);

			if (CheckBalance(st,s))
			{
				cout << "TRUE" << endl;
			}
			else
			{
				cout<<"FALSE"<<endl;
			}
			system("pause");
		}
		else if (lc == 5)
		{
			cin >> data;
			DecToBin(st, data);
			system("pause");
		}
		system("cls");
	}
}