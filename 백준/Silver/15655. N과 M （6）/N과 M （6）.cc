#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> result;
void recursive(int start, int depth, int array[]);

int main() {
    cin >> n >> m;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort(array, array + n);
    recursive(0, 0, array);
    
}

void recursive(int start, int depth, int array[]) {
    // basis part
    if (depth == m) {
        for(auto r:result) {
            cout << r << " ";
        }
        cout << "\n";
        return;
    }

    // inductive part
    for (int i = start; i < n; i++) {
        result.push_back(array[i]);
        recursive(i + 1, depth + 1, array);
        result.pop_back();
    }
}