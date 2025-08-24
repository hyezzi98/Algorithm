#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree;
vector<bool> visited;
int n, m;
void dfs(int cur);

int main() {
    int result = 0;
    cin >> n >> m;
    tree = vector<vector<int>> (n + 1);
    visited = vector<bool> (n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // for (auto t : tree) {
    //     for (auto graph : t) {
    //         cout << graph << " ";
    //     }
    //     cout << " ";
    // }
    // 방문하지 않은 곳 있다면 dfs탐색으로 연결요소 체크
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            result ++;
        }
    }
    cout << result;
    return 0;
}

void dfs(int cur) {
    visited[cur] = true;
    for (int next : tree[cur]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}