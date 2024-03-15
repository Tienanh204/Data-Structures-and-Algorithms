#include <iostream>
#include <algorithm>
#include <cstring>
#include <conio.h>
using namespace std;

int const maxn = 1000005;
int n, a[maxn], diff[maxn];
int BIT[maxn], BIT1[maxn], BIT2[maxn];
int BIT_MIN[maxn], BIT_DIFF[maxn];

// 1. Cap nhat gia tri:
void Update(int BIT[], int pos, int val) {
    for (; pos <= n; pos += pos & (-pos)) {
        BIT[pos] += val;
    }
}

// 2. Tinh tong tich luy:
int Query(int BIT[], int pos) {
    int s = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        s += BIT[pos];
    }
    return s;
}

// 3. Tim kiem phan tu cu the:
int search_Value(int BIT[], int x) {
    for (int i = 1; i <= n; i++) {
        if (Query(BIT, i) == x) return i;
    }
    return -1;
}

// 4. Truy van pham vi va cap nhat diem:
// - Truy van pham vi:
int range_Query(int BIT[], int l, int r) {
    return Query(BIT, r) - Query(BIT, l - 1);
}
// - Cap nhat diem:
void update_Increase_To(int BIT[], int ans, int x) {
    Update(BIT, ans, x);
}

void buildDifferenceArray() { // Xay dung mang hieu 
    for (int i = 1; i <= n; i++) {
        if (i == 1) diff[i] = a[i];
        else {
            diff[i] = a[i] - a[i - 1];
        }
    }
}

// 5. Cap nhat pham vi va truy van dem:
// - Cap nhat pham vi:
void updatePoint(int BIT[], int pos, int val) {
    for (; pos <= n; pos += pos & (-pos)) {
        BIT[pos] += val;
    }
}
void updateRange(int BIT[], int l, int r, int x) {
    Update(BIT, l, x);
    Update(BIT, r + 1, -x);
}
// - Truy van diem:
int Get(int BIT[], int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & (-idx)) {
        ans += BIT[idx];
    }
    return ans;
}

// 6. Cap nhat pham vi va truy van pham vi:
// - Cap nhat pham vi:
void update_Point(int BIT[], int pos, int val) {
    for (; pos <= n; pos += pos & (-pos)) {
        BIT[pos] += val;
    }
}
void update_Range(int l, int r, int x) {
    update_Point(BIT1, l, x);
    update_Point(BIT1, r + 1, -x);
    update_Point(BIT2, l, x * (l - 1));
    update_Point(BIT2, r + 1, -x * r);
}
// - Truy van pham vi:
int getSumOnBIT(int BIT[], int pos) {
    int ans = 0;
    for (; pos > 0; pos -= pos & (-pos)) {
        ans += BIT[pos];
    }
    return ans;
}
int prefixSum(int u) {
    return getSumOnBIT(BIT1, u) * u - getSumOnBIT(BIT2, u);
}
int rangeSum(int l, int r) {
    return prefixSum(r) - prefixSum(l - 1);
}

// 7. Tim tong cua k phan tu lien tiep sau mot vi tri cu the:
int next_k_Sum(int BIT[], int i, int k) {
    return Query(BIT, i + k) - Query(BIT, i);
}

// 8. Tim gia tri nho nhat trong khoang tu 0 toi r:
int get_Min(int BIT_MIN[], int r) {
    int Min = maxn;
    for (; r > 0; r -= r & (-r)) {
        Min = min(Min, BIT_MIN[r]);
    }
    return Min;
}
void update_Min(int BIT_MIN[], int pos, int val) {
    for (; pos <= n; pos += pos & (-pos)) {
        BIT_MIN[pos] = min(BIT_MIN[pos], val);
    }
}

// 9. Xay dung cay Fenwick tu day so ban dau:
void buildBIT(int BIT[], int a[]) {
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Update(BIT, i, a[i]);
        update_Min(BIT_MIN, i, a[i]);
    }
}

int main() {
    memset(BIT, 0, sizeof(BIT));
    memset(BIT_MIN, maxn, sizeof(BIT_MIN));
    bool k = true;
    while (k) {
        cout << "----------------------------- THAO TAC ------------------------------" << endl;
        cout << "1. Xay dung cay Fenwick." << endl;
        cout << "2. Tinh tong tich luy cua tung phan tu trong mang." << endl;
        cout << "3. Tim kiem phan tu cu the." << endl;
        cout << "4. Truy van pham vi va cap nhat diem." << endl;
        cout << "5. Cap nhat pham vi va truy van diem." << endl;
        cout << "6. Cap nhat pham vi va truy van pham vi." << endl;
        cout << "7. Tim tong cua k phan tu lien tiep sau mot vi tri cu the." << endl;
        cout << "8. Tim gia tri nho nhat trong khoang tu 0 toi r cua mang." << endl;
        cout << "---------------------------------------------------------------------" << endl;
        int sl;
        cout << "Chon thao tac ban muon thuc hien: "; cin >> sl;
        if (sl == 1) {
            cout << "Nhap vao so luong phan tu cua mang: "; cin >> n;
            cout << "Nhap vao gia tri cua tung phan tu trong mang: ";
            buildBIT(BIT, a);
            cout << "Cay Fenwick sau khi duoc xay dung la: ";
            for (int i = 1; i <= n; i++) cout << BIT[i] << " ";
            cout << endl;
        }
        else if (sl == 2) {
            cout << "Tong tich luy cua tung phan tu trong mang la: ";
            for (int i = 1; i <= n; i++) cout << Query(BIT, i) << " ";
            cout << endl;
        }
        else if (sl == 3) {
            int x;
            cout << "Nhap gia tri tong tich luy: "; cin >> x;
            int tmp = search_Value(BIT, x);
            if (tmp != -1) cout << "Gia tri " << x << " la tong tich luy cua phan tu dang o vi tri " << tmp << endl;
            else cout << "Khong co vi tri nao trong mang co tong tich luy bang voi " << x << endl;
        }
        else if (sl == 4) {
            int l, r;
            cout << "Nhap vao gia tri l, r cua doan [l, r] ma ban muon truy van: "; cin >> l >> r;
            cout << "Tong cua doan [l, r] la: " << range_Query(BIT, l, r) << endl;
            int ans, x;
            cout << "Nhap vao vi tri muon cap nhat va gia tri can them vao: "; cin >> ans >> x;
            update_Increase_To(BIT, ans, x);
            cout << "Gia tri cua cay Fenwick sau khi cap nhat diem la: ";
            for (int i = 1; i <= n; i++) cout << BIT[i] << " ";
            cout << endl;
        }
        else if (sl == 5) {
            memset(BIT_DIFF, 0, sizeof(BIT_DIFF));
            memset(diff, 0, sizeof(diff));
            buildDifferenceArray();
            for (int i = 1; i <= n; i++) {
                updatePoint(BIT_DIFF, i, diff[i]);
            }
            int l, r, x;
            cout << "Nhap vao gia tri l r va gia tri muon tang them trong doan [l, r]: "; cin >> l >> r >> x;
            updateRange(BIT_DIFF, l, r, x);
            int idx;
            cout << "Nhap vao vi tri trong mang ma ban muon truy van: "; cin >> idx;
            cout << "Gia tri cua phan tu trong mang sau khi thay doi gia tri trong doan [l, r] la: " << Get(BIT_DIFF, idx) << endl;
        }
        else if (sl == 6) {
            memset(BIT1, 0, sizeof(BIT1));
            memset(BIT2, 0, sizeof(BIT2));
            memset(diff, 0, sizeof(diff));
            buildDifferenceArray();
            for (int i = 1; i <= n; i++) {
                update_Point(BIT1, i, diff[i]);
                update_Point(BIT2, i, diff[i]);
            }
            int l, r, x;
            cout << "Nhap vao gia tri l r va gia tri muon tang them trong doan [l, r]: "; cin >> l >> r >> x;
            update_Range(l, r, x);
            int u, v;
            cout << "Nhap vao gia tri u v trong doan [u, v] ma ban muon truy van: "; cin >> u >> v;
            cout << "Gia tri tong trong doan [u, v] la: " << rangeSum(u, v) << endl;
        }
        else if (sl == 7) {
            memset(BIT, 0, sizeof(BIT));
            cout << "Gia tri cua cac phan tu trong mang la: ";
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
            for (int i = 1; i <= n; i++) {
                Update(BIT, i, a[i]);
            }
            int pos, k;
            cout << "Nhap mot vi tri cu the va so luong phan tu lien tiep sau vi tri do de tinh tong la: "; cin >> pos >> k;
            cout << "Tong cua " << k << " phan tu lien tiep sau vi tri " << pos << " la: " << next_k_Sum(BIT, pos, k);
            cout << endl;
        }
        else if (sl == 8) {
            cout << "Gia tri cua cac phan tu trong mang la: ";
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
            for (int i = 1; i <= n; i++) {
                cout << "Gia tri nho nhat trong khoang tu 0 toi " << i << " la: ";
                cout << get_Min(BIT_MIN, i) << endl;
            }
        }
        else {
            k = false;
        }
        _getch();
        system("cls");
    }
    return 0;
}






