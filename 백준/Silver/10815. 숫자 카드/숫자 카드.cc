#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> card;
vector<int> arr;
int binarySearch(int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (card[mid] == target) return 1;
        else if (card[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return 0;
}

int main() {
    cin >> n;
    card.resize(n);
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        card[i] = number;
    }

    sort(card.begin(), card.end());

    cin >> m;
    arr.resize(m);
    for (int i = 0; i < m; i++) {
        int number;
        cin >> number;
        arr[i] = number;
    }

    for (int i = 0; i < m; i++) {
        int target = arr[i];
        cout << binarySearch(0,n - 1,target) << " ";
    }
}