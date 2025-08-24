#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr;
int k, target;
long long result = 0;
void binarySearch(long long start, long long end) {
    while (start <= end) {
        int cnt = 0;
        long long mid = (start + end) / 2;
        // 랜선 자르기
        for (int i = 0; i < k; i++) {
            cnt += arr[i] / mid;
        }
        if (cnt < target) end = mid - 1;
        else {
            start = mid + 1;
            result = max(result, mid);
        }
    }
        
}
int main() {
    cin >> k >> target;
    arr.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
 
    binarySearch(1,arr[k - 1]);
    cout << result;
    return 0;
}