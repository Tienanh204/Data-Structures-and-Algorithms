#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n;
#define MAXN 1005
vector<int> adj[MAXN];
int parent[MAXN];
bool visited[MAXN];

void nhap()
{
	ifstream fin;
	fin.open("01.txt", ios::in);
	if (!fin)
	{
		cout << "Can't open file" << endl;
		return;
	}
	fin >> n;
	while (!fin.eof())
	{
		int x, y;
		fin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	fin.close();
}

void DFS(int u)
{
	visited[u] = true;
	for (int v : adj[u])
	{
		if (!visited[v])
		{
			DFS(v);
			parent[v] = u;
		}
	}
}

int main()
{
	memset(visited, false, sizeof(visited));
	nhap();

	int s = 1, t = 3;
	DFS(s);
	vector<int> res;
	while (t != s)
	{
		res.push_back(t);
		t = parent[t];
	}
	res.push_back(s);
	reverse(res.begin(), res.end());
	for (int x : res)
	{
		cout << x << " ";
	}
	cout << endl;
}

//************************************************************

#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<vector>
#include<climits> 
using namespace std;

#define MAXN 1005
struct edge
{
    int x, y, w;
};

vector<pair<int, int>> adj[MAXN];
int parent[MAXN];
int dist[MAXN];
bool taken[MAXN];
int n;

void nhap() {
    ifstream fin;
    fin.open("02.txt", ios::in);
    if (!fin) {
        cout << "Can't open file" << endl;
        return;
    }
    fin >> n;
    int x, y, w;
    while (fin >> x >> y >> w) 
    {
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }
    memset(taken, false, sizeof(taken));
    for (int i = 0; i <= n; i++) {
        dist[i] = MAXN;
        parent[i] = 1;
    }
    fin.close();
}

//2.1
//Dijkstra: Tim duong di ngan nhat tu 1 
//dinh den moi dinh tren do thi
void Dijkstra(int s, int t)
{
	dist[s] = 0;
	vector<edge> MST;
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>>Q;
	Q.push({ 0,s });
	long long d = 0;
	while (!Q.empty())
	{
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second, distU = top.first;
		if (distU > dist[u])
			continue;
		if (s != u)
		{
			MST.push_back({ parent[u], u ,distU });
		}
		for (auto it : adj[u])
		{
			int v = it.first, weightV = it.second;
			if (dist[v] > dist[u] + weightV)
			{
				dist[v] = dist[u] + weightV;
				parent[v] = u;
				Q.push({ dist[v],v });
			}
		}
	}
	if (dist[t] == MAXN)
	{
		cout << "Khong co duong di" << endl;
	}
	else
	{
		cout << "Trong so: " << d << endl;
		cout << "Duong di" << endl;
		for (auto it : MST)
		{
			cout << it.x << " " << it.y << " " << it.w << endl;
		}
	}
}

//Dijkstra1: Tim duong di ngan nhat
//giua 2 dinh s->t
void Dijkstra1(int s, int t) {
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>> Q;
	Q.push({ 0,s });

	while (!Q.empty()) {
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second, distU = top.first;

		if (u == t && parent[t] != MAXN) {
			// Tìm thấy đường đi từ s đến t, thoát khỏi vòng lặp
			break;
		}

		if (distU > dist[u]) {
			continue;
		}

		for (auto it : adj[u]) {
			int v = it.first, weightV = it.second;

			if (dist[v] > dist[u] + weightV) {
				dist[v] = dist[u] + weightV;
				parent[v] = u;
				Q.push({ dist[v],v });
			}
		}
	}
	if (dist[t] == MAXN)
	{
		cout << "Khong co duong di" << endl;
	}
	else 
	{
		cout << "Trong so: " << dist[t] << endl;
		cout << "Duong di: ";
		//Truy vet
		vector<int> path;
		int current = t;
		while (current != s) {
			path.push_back(current);
			current = parent[current];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for (int x : path)
		{
			cout << x << " ";
		}
		cout << endl;
	}
}


//2.2
//Prim: Tim cay khung cuc tieu
void Prim(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>>Q;
	int d = 0;
	long long dem = 0;
	vector<edge> MST;
	taken[s] = true;
	for (auto it : adj[s])
	{
		if (!taken[it.first])
		{
			Q.push({ it.second,it.first });
			dist[it.first] = it.second;
			parent[it.first] = s;
		}
	}
	while (!Q.empty())
	{
		pair<int, int> e = Q.top(); Q.pop();
		int u = e.second, distU = e.first;
		cout << u << " " << distU << endl;
		if (!taken[u])
		{
			taken[u] = true;
			d += distU;
			++dem;
			if (u != s)
			{
				MST.push_back({ parent[u], u, distU });//Neu muon in theo trong so cong don thi thay w->d
			}
			for (auto it : adj[u])
			{
				int v = it.first, weighV = it.second;
				if (!taken[it.first] && weighV < dist[v])
				{
					dist[v] = weighV;
					parent[v] = u;
					Q.push({ weighV,v });
				}
			}
		}
	}
	if (dem == n - 1)
	{
		cout << "Trong so: " << d << endl;
		cout << "Cay khung" << endl;
		for (auto it : MST)
		{
			cout << it.x << " " << it.y << " " << it.w << endl;
		}
	}
	else
		cout << "IMPOSSIBLE" << endl;
}

int main()
{
    nhap();
	//Dijkstra1(5, 6);
	//nhap();
	//Dijkstra1(6, 3);
    Prim(1);
}

//7
//0 2 1
//0 4 3
//0 5 5
//1 4 7
//1 5 1
//1 6 8
//2 3 3
//2 4 5
//4 5 7
//6 4 2


#include <iostream>
using namespace std;

class HinhTron {
private:
	const float PI = 3.14f;
	float banKinh;
	float chuVi;
	float dienTich;

public:
	// Constructor
	HinhTron(float banKinh) {
		this->banKinh = banKinh;
	}

	float getChuVi() {
		return chuVi;
	}

	float getDienTich() {
		return dienTich;
	}

	void tinhChuVi() {
		chuVi = 2 * PI * banKinh;
	}

	void tinhDienTich() {
		dienTich = PI * banKinh * banKinh;
	}
};

int main() {
	HinhTron hinhTron(20);
	hinhTron.tinhChuVi();
	hinhTron.tinhDienTich();
	float chuVi = hinhTron.getChuVi();
	float dienTich = hinhTron.getDienTich();
	cout << "Chu vi hinh tron: " << chuVi << "; Va dien tich: " << dienTich << endl;
	return 0;
}


class SinhVien {
private:
	string ten;
	int tuoi;

	void setTen(string ten) {
		if (ten.empty()) {
			// Nếu biến ten rỗng, thì đặt tên là "Không biết"
			this->ten = "Không biết";
		}
		else {
			this->ten = ten;
		}
	}

	void setTuoi(int tuoi) {
		// Kiểm tra tuổi có hợp lệ không
		if (tuoi > 18) {
			this->tuoi = tuoi;
		}
		else {
			this->tuoi = -1; // Giá trị -1 để biểu thị tuổi không hợp lệ
		}
	}

public:
	// Constructor
	SinhVien(string ten, int tuoi) {
		setTen(ten);
		setTuoi(tuoi);
	}

	string getTen() {
		return ten;
	}

	string getTuoi() {
		if (tuoi != -1) {
			// Nếu tuổi hợp lệ, trả về dạng string
			return to_string(tuoi);
		}
		else {
			return "Tuổi không hợp lệ";
		}
	}
};

int main() {
	// Khởi tạo các đối tượng SinhVien
	SinhVien sinhVien1("", 23);
	SinhVien sinhVien2("Peter", 17);

	// In thông tin của các sinh viên
	cout << "Sinh viên 1 có tên: " << sinhVien1.getTen() << ", tuổi: " << sinhVien1.getTuoi() << endl;
	cout << "Sinh viên 2 có tên: " << sinhVien2.getTen() << ", tuổi: " << sinhVien2.getTuoi() << endl;

	return 0;
}