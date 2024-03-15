#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ke[1005];
bool visited[1005];
vector<vector<int>> allPaths;
vector<int> currentPath;

void DFS(int u, int t)
{
    visited[u] = true;
    currentPath.push_back(u);
    if (u == t)
    {
        allPaths.push_back(currentPath);
    }
    else {
        for (int v : ke[u])
        {
            if (!visited[v]) 
            {
                DFS(v, t);
            }
        }
    }
    visited[u] = false; 
    currentPath.pop_back(); 
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    int s, t;
    cin >> s >> t;
    memset(visited, false, sizeof(visited));
    DFS(s, t);

    if (allPaths.empty())
    {
        cout << "Khong co duong di" << endl;
    }
    else
    {
        for (int i = 0; i < allPaths.size(); i++)
        {
            for (int j = 0; j < allPaths[i].size(); j++)
            {
                cout << allPaths[i][j] << " ";
            }
            cout << endl;
        }
    }
}
