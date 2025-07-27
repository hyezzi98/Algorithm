#include <iostream>
#include <vector>
using namespace std;
vector<int> array;
void combination(int depth, int start);
int n, m;

int main() {
    cin >> n >> m;
    combination(0, 1);
}

void combination(int depth, int start) {
    // cout << "**" << "\n";
    // cout  << depth << "\n";
    // basis part
    if (depth == m) {
        for (auto arr : array) {
            cout << arr << " ";
        }
        cout << "\n";
        return;
    }

    // inductive part
    for (int i = start; i <= n; i++) {
        array.push_back(i);
        combination(depth + 1, i);
        array.pop_back();
    }
    
}