#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
int n;

struct hashNode
{
	int key; int value;
	bool filled = false;
};
typedef struct hashNode* hn;
vector<hashNode*> table;
// Linear probing & Quadratic Probing & Double hashing


int hashFunction(int key)
{
	return key % n;
}

int findNextSlot(int index)
{
	int i = (index + 1) % n;
	while (table[i]->filled)
	{
		i = (i + 1) % n;
	}
	return i;
}

void insert(int key, int value)
{
	int index = hashFunction(key);

	if (table[index]->filled == true)
	{
		index = findNextSlot(index);
	}
	table[index]->key = key;
	table[index]->value = value;
	table[index]->filled = true;
}

void remove(int key, int value)
{
	int index = hashFunction(key);
	int originalIndex = index;

	while (table[index]->filled && table[index]->key != key)
	{
		index = (index + 1) % n;

		//Neu qua ve vi tri ban dau, dung de tranh vong lap vo han
		if (index == originalIndex)
			return;//Khong tim thay phan tu de xoa
	}
	if (table[index]->filled && table[index]->key == key)
	{
		table[index]->filled = false;//Danh dau cho nay da xoa va co the them ptu khac vao day
	}
}

int search(int key)
{
	int index = hashFunction(key);
	int originalIndex = index;

	while (table[index]->filled && table[index]->key != key)
	{
		index = (index + 1) % n;

		if (originalIndex == index)
			return -1;//Khong thay phan tu can tim
	}
	if (table[index]->filled && table[index]->key == key)
	{
		return table[index]->value;
	}
	else
	{
		return -1;
	}
}

void display(vector<hn> table)
{
	for (int i = 0; i < table.size(); i++)
	{
		cout << "(" << table[i]->key << "," << table[i]->value << ")" << endl;
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		hn newNode = new hashNode();
		table.push_back(newNode);
	}
	for (int i = 0; i < n; i++)
	{
		int key, value;
		cin >> key >> value;
		insert(key, value);
	}
	display(table);
}