#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
long long result = 0;
vector<int> arr;
void binarySearch(int start, int end, int target) {
    while (start <= end) {
        long long mid = (start + end) / 2;
        long long length = 0;
        // mid 크기만큼 절단기 설정하기
        for (int i = 0; i < n; i++) {
            if (arr[i] >= mid) {
                length += arr[i] - mid;
            }
        }
        // 길이 부족하면 절단기 높이 낮추기
        if (length < target) {
            end = mid - 1;
        }
        // length 갱신
        if (length >= target) {
            start = mid + 1;
            result = max(result, mid);
        }
        
    }
} 

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    binarySearch(0, arr[n - 1], m);
    cout << result;

    // for (auto a : arr) {
    //     cout << a << " ";
    // }
}