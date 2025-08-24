#include <iostream>
#include <queue>
#include <vector>
#define DIR 4
using namespace std;

vector<pair<int,int>> startPos(2);
int n, m;
// 남동북서
int dy[DIR] = {1, 0, -1, 0};
int dx[DIR] = {0, 1, 0, -1};
char arr[30][30];

bool isValid(int y, int x) {
    if (0 > y || n <= y || 0 > x || m <= x) return false;
    else return true;
}

int move(int y, int x) {
    // 바로 이동할 방향 탐색 (이동 -> 방향전환)
    int d = -1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!isValid(ny,nx) || arr[ny][nx] == '.') continue;

        if (i == 0) {
            if (arr[ny][nx] == '|' || arr[ny][nx] == '+' || arr[ny][nx] == '2' || arr[ny][nx] == '3') d = 0;
        } else if (i == 1) {
            if (arr[ny][nx] == '-' || arr[ny][nx] == '+' || arr[ny][nx] == '3' || arr[ny][nx] == '4') d = 1;
        } else if (i == 2) {
            if (arr[ny][nx] == '|' || arr[ny][nx] == '+' || arr[ny][nx] == '1' || arr[ny][nx] == '4') d = 2;
        } else if (i == 3) {
            if (arr[ny][nx] == '-' || arr[ny][nx] == '+' || arr[ny][nx] == '1' || arr[ny][nx] == '2') d = 3;
        }
    }
    return d;
}

void findPipe(int y,  int x) {
    // 어떤 방향에 파이프 놓을 수 있는지 탐색
    int dir[4] = {0};

    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(!isValid(ny, nx)) continue;

        // 이어져야하는 방향
        if (d == 0) {
            if (arr[ny][nx] == '|' || arr[ny][nx] == '+' || arr[ny][nx] == '2' || arr[ny][nx] == '3') dir[d] = 1;
        } else if (d == 1) {
            if (arr[ny][nx] == '-' || arr[ny][nx] == '+' || arr[ny][nx] == '3' || arr[ny][nx] == '4') dir[d] = 1;
        } else if (d == 2) {
            if (arr[ny][nx] == '|' || arr[ny][nx] == '+' || arr[ny][nx] == '1' || arr[ny][nx] == '4') dir[d] = 1;
        } else if (d == 3) {
            if (arr[ny][nx] == '-' || arr[ny][nx] == '+' || arr[ny][nx] == '1' || arr[ny][nx] == '2') dir[d] = 1;
        }
 
    }
    // 놓을 수 있는 방향에 따라 파이프 출력
    if (dir[0] && dir[1] && dir[2] && dir[3]) {
        cout << y + 1 << " " << x + 1 << " " << '+';
    } else if (dir[0] && !dir[1] && dir[2] && !dir[3]) {
        cout << y + 1 << " " << x + 1 << " " << '|';
    } else if (!dir[0] && dir[1] && !dir[2] && dir[3]) {
        cout << y + 1 << " " << x + 1 << " " << '-';
    } else if (dir[0] && dir[1] && !dir[2] && !dir[3]) {
        cout << y + 1 << " " << x + 1 << " " << '1';
    } else if (!dir[0] && dir[1] && dir[2] && !dir[3]) {
        cout << y + 1 << " " << x + 1 << " " << '2';
    } else if (!dir[0] && !dir[1] && dir[2] && dir[3]) {
        cout << y + 1 << " " << x + 1 << " " << '3';
    } else if (dir[0] && !dir[1] && !dir[2] && dir[3]) {
        cout << y + 1 << " " << x + 1 << " " << '4';
    }
}


void setStartPos() {
    // 1. M부터 상하좌우 탐색하기
    int y = startPos[0].first;
    int x = startPos[0].second;
    int d = move(y, x);
    // 2. M부터 시작 불가하다면 시작점을 Z로 변경
    if (d == -1) {
        y = startPos[1].first;
        x = startPos[1].second;
        d = move(y, x);
    }

    queue<pair<pair<int,int>, int>> q;
    q.push({{y, x}, d});

    while (!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        d = q.front().second;
        q.pop();

        int ny = y + dy[d];
        int nx = x + dx[d];
        int nd = -1;

        // 새로 간 곳에 .이 있으면 파이프를 놓기
        if (arr[ny][nx] == '.')  {
            findPipe(ny, nx);
            return;
        }

        if (d == 0) {
            if (arr[ny][nx] == '|' || arr[ny][nx] == '+') nd = 0;
            else if (arr[ny][nx] == '2') nd = 1;
            else if (arr[ny][nx] == '3') nd = 3;
        } else if (d == 1) {
            if (arr[ny][nx] == '-' || arr[ny][nx] == '+') nd = 1;
            else if (arr[ny][nx] == '3') nd = 2;
            else if (arr[ny][nx] == '4') nd = 0;
        } else if (d == 2) {
            if (arr[ny][nx] == '|' || arr[ny][nx] == '+') nd = 2;
            else if (arr[ny][nx] == '1') nd = 1;
            else if (arr[ny][nx] == '4') nd = 3;
        } else if (d == 3) {
            if (arr[ny][nx] == '-' || arr[ny][nx] == '+') nd = 3;
            else if (arr[ny][nx] == '1') nd = 0;
            else if (arr[ny][nx] == '2') nd = 2;
        }
        // 다음 탐색 방향 지정
        if (nd != -1) q.push({{ny, nx}, nd});
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            // 1. 시작점 탐색하기
            if (arr[i][j] == 'M') {
                startPos[0] = {i, j};
            } else if (arr[i][j] == 'Z') {
                startPos[1] = {i, j};
            }
        }
    }

    // 시작점 정한 후 이동
    setStartPos();

    return 0;
}
