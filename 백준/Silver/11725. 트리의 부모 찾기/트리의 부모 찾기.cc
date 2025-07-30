#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;
void dfs(int cur); 

int main() {
    int n;
    cin >> n;

    tree = vector<vector<int>>(n + 1);
    parent = vector<int>(n + 1);
    visited = vector<bool>(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

}

void dfs(int cur) {
    visited[cur] = true;
    for (int next : tree[cur]) {
        if (!visited[next]) {
            parent[next] = cur;
            dfs(next);
        }
    }
    
}