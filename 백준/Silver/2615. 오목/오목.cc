#include <iostream>
#define ARRSIZE 19
using namespace std;

int array[19][19];

// 오목 방향만 확인
int dy[4] = {0, 1, 1, -1};
int dx[4] = {1, 0, 1, 1};

void print(int array[ARRSIZE][ARRSIZE]);
bool checkFive(int y, int x);

int main() {
    bool result;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> array[i][j];
        }
    }
    // print(array);
    // 바둑이 놓인 칸 탐색
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (array[i][j] != 0) {
                if (checkFive(i, j)) {
                    return 0;
                }
            }
        } 
    }
    cout << 0;
    return 0;
}

// 다섯 칸 연속 이어졌는지 확인
bool checkFive(int y, int x) {
    int number = array[y][x];

    for (int d = 0; d < 4; d++) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            int ny = y + dy[d] * i;
            int nx = x + dx[d] * i;
            if (0 > ny || ny >= ARRSIZE || 0 > nx || nx >= ARRSIZE || array[ny][nx] != number) break;
            count++;
        }
        // 6목 체크
        if (count == 5) {
            int prevY = y - dy[d];
            int prevX = x - dx[d];
            int nextY = y + (dy[d] * 5);
            int nextX = x + (dx[d] * 5);
            if ((0 > prevY || 0 > prevX || ARRSIZE <= prevY || ARRSIZE <= prevX || array[prevY][prevX] != number) &&
                (0 > nextY || 0 > nextX || ARRSIZE <= nextY || ARRSIZE <= nextX || array[nextY][nextX] != number)) {
                    cout << number << "\n" << y + 1 << " " << x + 1;
                    return true;
                }    
        }
    }
    return false;
}

void print(int array[ARRSIZE][ARRSIZE]) {
    for (int i = 0; i < ARRSIZE; i++) {
        for (int j = 0; j < ARRSIZE; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}