#include<iostream>
#include<math.h>
#include<time.h>
#include<ctime>
#include<string>
using namespace std;

int Fn(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    if (n == 2)
        return 5;
    return Fn(n-1) + Fn(n - 2) * Fn(n+1);
}


int Fn1(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    if (n == 2)
        return 5;

    int fn0 = 1, fn1 = 2, fn2 = 5;
    int fn3;
    for (int i = 3; i <= n; i++) {
        fn3 = fn1 + fn0 * fn2;
        fn0 = fn1;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn2;
}



int main()
{
	int n; cin >> n;
	cout << Fn(n) << endl;
	cout << Fn1(n) << endl;
}
/*
-Cau 1: goi de quy qua sau gay ra viec lap lai cac phan tu da duyet-> tran bo nho 
-Cau 2: hieu qua hon rat nhieu khi do phuc tap chi la O(n) va cho ket qua nhanh hon
*/