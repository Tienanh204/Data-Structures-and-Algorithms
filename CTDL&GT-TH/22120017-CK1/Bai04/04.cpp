#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int n, k;
int* a = new int[n];

//Do phuc tap O(n^2)

bool selectionSort()
{
	cout << "n: "; cin >> n;
	cout << "a[]: ";
	int m = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "k: ";
	cin >> k;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == k)
			{
				return true;
			}
		}
	}
	return false;
}

//Do phuc tap O(n)
void countingSort(vector<int>& inArray)
{
	n = inArray.size();
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		m = max(m, inArray[i]);
	}

	vector<int> cntArray(m + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cntArray[inArray[i]]++;
	}

	for (int i = 1; i <= m; i++)
	{
		cntArray[i] += cntArray[i - 1];
	}

	vector<int> outArray(n);
	for (int i = n - 1; i >= 0; i--)

	{
		outArray[cntArray[inArray[i]] - 1] = inArray[i];

		cntArray[inArray[i]]--;
	}
	inArray = outArray;
}
bool check()
{
	cout << "n: "; cin >> n;
	cout << "a[]: ";
	vector<int> inArray;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		inArray.push_back(x);
	}
	cout << "k: ";
	cin >> k;
	countingSort(inArray);

	int l = 0;
	int r = inArray.size() - 1;

	while (l < r)
	{
		if (inArray[l] + inArray[r] == k)
			return true;
		if (inArray[l] + inArray[r] > k)
		{
			r--;
		}
		else if (inArray[l] + inArray[r] < k)
		{
			l++;
		}
	}
	return false;
}

int main()
{
	//cout << selectionSort() << endl;
	cout << check() << endl;
	delete[]a;
}