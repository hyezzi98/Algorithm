#include <iostream>
#include <vector>
using namespace std;

void recursive(int depth, bool visited[], vector<int> &array);
int n, m;

int main() {
    cin >> n >> m;
    bool visited[n + 1] = {false};
    vector<int> array;
    recursive(0, visited, array);
}

void recursive(int depth, bool visited[], vector<int> &array) {
    // basis part
    if (depth == m) {
        for (auto arr : array) {
            cout << arr << " ";
        }
        cout << "\n";
        return;
    }

    // inductive part
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            array.push_back(i);
            recursive(depth + 1, visited, array);
            visited[i] = false;
            array.pop_back();
        }
    }
}