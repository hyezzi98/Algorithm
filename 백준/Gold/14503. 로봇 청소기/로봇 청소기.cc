#include <iostream>
#include <vector>
using namespace std;
// 북동남서
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> arr;
int cnt = 0;
int n, m;

void robotCleaner(int y, int x, int d) {
    int flag = 0; 
    // 현재 칸 청소 가능하다면 청소하기
    if (arr[y][x] == 0) {
        // cout << y << " " << x << "\n";
        arr[y][x] = 2;
        cnt++;
    }

    // 주변 4칸중 청소되지 않은 빈 칸 있는지 확인
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 주변 4칸중 청소되지 않은 칸이 있는지 확인
        if (0 <= ny && 0 <= nx && ny < n && nx < m && arr[ny][nx] == 0) {
            flag = 1;
            break;
        }
    }

    // 청소하지 않은 빈칸이 있는 경우
    // if (flag == 1) {
    //     // 1. 반시계 방향으로 회전
    //     d = (d + 3) % 4;
    //     // 2. 앞쪽 칸 청소되지 않았는지 확인
    //     int frontY = y + dy[d];
    //     int frontX = x + dx[d];
    //     if (0 <= frontY && 0 <= frontX && frontY < n && frontX < m) {
    //         // 청소되지 않은 경우 전진
    //         if (arr[frontY][frontX] == 0) {
    //             robotCleaner(frontY, frontX, d);   
    //         }
    //         // 청소된 칸인 경우 유지
    //         else if (arr[frontY][frontX] == 2) {
    //             robotCleaner(y, x, d);
    //         }
    //     }
    // }
    if (flag == 1) {
    for (int i = 0; i < 4; i++) {
        d = (d + 3) % 4; // 반시계 회전
        int frontY = y + dy[d];
        int frontX = x + dx[d];
        if (0 <= frontY && 0 <= frontX && frontY < n && frontX < m && arr[frontY][frontX] == 0) {
            robotCleaner(frontY, frontX, d);
            return; // 이동했으면 바로 종료 (재귀에서 계속 탐색)
            }
        }
    }


    // 빈 칸이 없는 경우
    // 한칸 후진하고 1번으로 돌아가기
    else {
        int frontY = y - dy[d];
        int frontX = x - dx[d];
        if (0 <= frontY && 0 <= frontX && frontY < n && frontX < m) {
            if (arr[frontY][frontX] == 1) {
                return;
            }
            else {
                robotCleaner(frontY, frontX, d);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(m);
    }
    int y, x, d;
    cin >> y >> x >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    robotCleaner(y, x, d);
    cout << cnt;
    return 0;
}