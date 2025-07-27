#include <iostream>
#include <vector>
using namespace std;
vector<int> array;
void combination(int start, int depth);
int n, m;

int main() {
    cin >> n >> m;
    combination(1, 0);
}

void combination(int start, int depth) {
    // basis part
    if (depth == m) {
        for (auto arr : array) {
            cout << arr << " ";
        }
        cout << "\n";
    }

    // inductive part
    for (int i = start; i <= n; i++) {
        array.push_back(i);
        combination(i + 1, depth + 1);
        array.pop_back();
    }
}