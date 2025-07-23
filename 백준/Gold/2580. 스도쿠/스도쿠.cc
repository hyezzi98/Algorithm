#include <iostream>
#include <vector>
using namespace std;

void recursive(int depth);

vector<pair<int, int>> blankList;

int array[9][9];
bool visitedRow[10][9];
bool visitedColumn[10][9];
bool visitedSquare[10][9];

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> array[i][j];
        }
    }

    // visited 배열 초기화
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            visitedRow[i][j] = false;
            visitedColumn[i][j] = false;
            visitedSquare[i][j] = false;
        }
    }

    // 값이 0인 좌표 넣기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = array[i][j];
            if (num == 0) {
                blankList.push_back({i, j});
            } else {
                visitedRow[i][num] = true;
                visitedColumn[j][num] = true;
                int squareBox = (i / 3) * 3 + (j / 3);
                visitedSquare[squareBox][num] = true;
            }
        }
    }

    recursive(0);
    return 0;
}

void recursive(int depth) {
    // basis part
    if (depth == blankList.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << array[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    // inductive part -> 숫자 탐색
    int y = blankList[depth].first;
    int x = blankList[depth].second;
    int squareBox = (y / 3) * 3 + (x / 3);

    for (int i = 1; i < 10; i++) {
        if (!visitedRow[y][i] && !visitedColumn[x][i] && !visitedSquare[squareBox][i]) {
            array[y][x] = i;
            visitedRow[y][i] = true;
            visitedColumn[x][i] = true;
            visitedSquare[squareBox][i] = true;

            recursive(depth + 1);

            // 돌리기
            array[y][x] = 0;
            visitedRow[y][i] = false;
            visitedColumn[x][i] = false;
            visitedSquare[squareBox][i] = false;
        }
    }
}
