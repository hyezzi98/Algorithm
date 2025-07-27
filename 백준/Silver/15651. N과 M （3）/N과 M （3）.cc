#include <iostream>
#include <vector>
using namespace std;
vector<int> array;
void permutation(int depth);
int n, m;

int main() {
    cin >> n >> m;
    permutation(0);
}

void permutation(int depth) {
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
    for (int i = 1; i <= n; i++) {
        array.push_back(i);
        permutation(depth + 1);
        array.pop_back();
    }
    
}