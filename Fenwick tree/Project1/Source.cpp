#include<iostream>
#include<string>
using namespace std;

int const maxn = 1000005;
int binaryIndexedTree[maxn], n;//Mang de luu tong tren cay
int input[maxn];//Mang de xay dung cay


/*
- Fenwick tree hoac cay binary index tree lad CTDL cung cap
cac phuong thuc hieu qua de tinh toan voi cac tong tien to cua mot bang gia tr
    * Do phuc tap ve khong gian cua cay: O(n)
	* Do phuc tap ve thoi gian tao cay: O(nlogn)
	* Do phuc tap ve thoi gian cap nhap gai tri: O(Logn)
	* Do phuc tap ve thoi gian de lay tong tien to: O(logn)
*/


/*
- De tim node cha
	 * 1) Tim bu 2 cua index
	 * 2) AND so bu 2 voi index
	 * 3) index - so tao ra sau B2
-> Outphut: La index cua node cha cua node hien tai
*/
int getParent(int index)
{
	return index - (index & -index);
}

/*
 * De tu node hien tai -> node tiep theo
	 * 1) Tim bu 2 cua index
	 * 2) AND so bu 2 voi index
	 * 3) index + so tao ra sau B2
-> Output: La index cua node ke tiep bat dau tu node hien tai
*/
int getNext(int index)
{
	return index + (index & -index);
}

//bat dau tu chi so index va cap nhap gia tri cho node nay,
//tiep tuc them gia tri nay cho node tiep theo den khi den duoc ngoai pham vi cua cay
void updateBinaryIndexedTree(int val, int index)
{
	while (index <= n)
	{
		binaryIndexedTree[index] += val;
		index = getNext(index);
	}
}

//Tinh tong tren doan [0,index]
int getSum(int index)
{
	int sum = 0;
	while (index > 0)
	{
		sum += binaryIndexedTree[index];
		index = getParent(index);
	}
	return sum;
}

//Tao cay cung giong nhu cap nhap cay cho moi gia tri trong mang
void createTree(int input[])
{
	for (int i = 1; i <= n; i++)
	{
		updateBinaryIndexedTree(input[i], i);
	}
}

//In ra cay Fenwick
void printTree()
{
	cout << "Fenwick Tree:" << endl;
	for (int i = 1; i <= n; i++) {
		cout << "BIT[" << i << "] = " << binaryIndexedTree[i] << endl;
	}
	cout << endl;
}


int main()
{
	cout << "N: ";
	cin >> n;
	cout << "input[]: ";
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}
	createTree(input);
	//cout << getSum(5) << endl;
	printTree();
	updateBinaryIndexedTree(1, 1);
	printTree();
}