#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void recursive(int depth, int array[], bool visited[]);

int n, m;
vector<int> result;
set<vector<int>> allResult;

int main() {
    cin >> n >> m;
    int array[n];
    bool visited[n] = {false};
    for (int i = 0 ; i < n; i++) {
        cin >> array[i];
    }
    sort(array, array + n);
    recursive(0, array, visited);
    for (const auto &all : allResult) {
        for (int num : all) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

void recursive(int depth, int array[], bool visited[]) {
    // basis part
    if (depth == m) {
        // 여기서 벡터에 저장
        allResult.insert(result);
        return;
    }

    // inductive part
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int number = array[i];
            visited[i] = true;
            result.push_back(number);
            recursive(depth + 1, array, visited);
            visited[i] = false;
            result.pop_back();
        }
    }
}