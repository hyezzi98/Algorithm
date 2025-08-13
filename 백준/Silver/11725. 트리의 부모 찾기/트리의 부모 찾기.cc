#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;
int n;

void dfs(int cur) {
    visited[cur] = true;
    for (auto next : tree[cur]) {
        if (!visited[next]) {
            parent[next] = cur;
            dfs(next);
        }
    }
}

int main() {
    cin >> n;
    tree.resize(n + 1);
    parent.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);
    for (int i = 2; i < n + 1; i++) {
        cout << parent[i] <<"\n";
    }
    
}