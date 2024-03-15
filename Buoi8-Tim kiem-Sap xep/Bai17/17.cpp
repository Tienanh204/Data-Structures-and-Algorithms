#include <iostream>
#include <algorithm>
using namespace std;

/*
Cho mang a gom n phan tu va so nguyen duong k. Dem so luong 
cap so ai,aj (i!=j) co tong bang k

Goi y: Sawp xep mang tang dan sau do voi moi phan tu cua a[i]
trong mang tim xem trong doan [i+1,n-1] co bao nhieu phan tu
co gia tri k-a[i] (rut duoc bieu thuc nay thong qua a[i]+a[j]=1)
bang cach tim vi tri dau tien va vi tri cuoi cung cua phan tu co gia tri k-a[i] ==> So luong
*/

int main()
{
    int n, k;
    cin >> n >> k;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        auto it1 = lower_bound(a + i + 1, a + n, k - a[i]);
        auto it2 = upper_bound(a + i + 1, a + n, k - a[i]);
        cnt += it2 - it1;
    }
    cout << cnt << endl;

    return 0;
}
