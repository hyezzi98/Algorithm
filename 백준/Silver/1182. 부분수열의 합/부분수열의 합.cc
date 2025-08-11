#include <iostream>
using namespace std;
int n,s;
int result = 0;
void recursive(int idx, int cur, int array[]) {
    
    // basis part
    if (idx == n) {
        if (cur == s) {
            result++;
        }
        return;
    }
    // inductive part
    int number = array[idx];
    recursive(idx + 1, cur + number, array);
    recursive(idx + 1, cur, array);
}
int main() {
    cin >> n >> s;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    recursive(0, 0, array);
    if (s == 0) result--;
    cout << result;
} 