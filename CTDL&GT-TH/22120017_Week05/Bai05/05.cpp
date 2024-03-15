#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
int a[1000001], n;


struct sv
{
	string id, name;
	int year;
};

void inputList(sv *&student)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien " << i + 1 << endl;
		cout << "MSSV: ";
		cin >> student[i].id;
		cout << "Name: ";
		cin.ignore();
		getline(cin, student[i].name);
		cout << "Year: ";
		cin >> student[i].year;
		cout << endl;
	}
}

void printList(sv*& student)
{
	cout << "************* DANH SACH SINH VIEN ************" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien " << i + 1 << endl;
		cout << "MSSV: " << student[i].id << endl;
		cout << "Name: " << student[i].name << endl;
		cout << "Year: " << student[i].year << endl;
		cout << endl;
	}
	cout << "**********************************************" << endl;
}

void ascendingID(sv*& student)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (student[min].id > student[j].id)
			{
				min = j;
			}
		}
		sv tmp = student[min];
		student[min] = student[i];
		student[i] = tmp;
	}
}

void ascendingName(sv*& student)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (student[min].name > student[j].name)
			{
				min = j;
			}
		}
		sv tmp = student[min];
		student[min] = student[i];
		student[i] = tmp;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (student[i].name == student[i+1].name)
		{
			if (student[i].year > student[i+1].year)
			{
				sv tmp = student[i];
				student[i] = student[i+1];
				student[i+1] = tmp;
			}
		}
	}
}

int main()
{
	cout << "N: ";
    cin >> n;
	sv *student = new sv[n];
	inputList(student);
	//ascendingID(student);
	ascendingName(student);
	printList(student);
}
//1005
//Tran Minh Thanh
//1991
//1001
//Tran Thi Bich
//1988
//1003
//Tran Minh Thanh
//1990
//1000
//Vo Quang Vinh
//1990
//1008
//Nguyen Van An
//1990