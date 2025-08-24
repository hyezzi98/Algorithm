#define SIZE 6
#include <vector>
#include <iostream>
using namespace std;
vector<int> result;
int k;
void recursive(int depth, int array[], int start) {
    // basis part
    if (depth == SIZE) {
        for (auto res : result) {
            cout << res << " ";
        }
        cout << "\n";
    }
    // inductive part
    for (int i = start; i < k; i++) {
        int number = array[i];
        result.push_back(number);
        recursive(depth + 1, array, i + 1);
        result.pop_back();
    }
}
int main() {
    while(true) {
        cin >> k;
        if (k == 0) {
            break;
        }
        int array[k];
        for (int i = 0; i < k; i++) {
            cin >> array[i];
        }

        // 6개 숫자 뽑기
        recursive(0, array, 0);
        cout << "\n";

        // for (int i = 0; i < k; i++) {
        //     cout << array[i] << " ";
        // }
        // cout << "\n";
    }
    return 0;
}