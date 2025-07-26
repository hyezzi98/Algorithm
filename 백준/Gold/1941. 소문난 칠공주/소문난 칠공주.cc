#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define SIZE 5
#define DIRECTION 4
using namespace std;

void printArray(char array[][SIZE]);
void combination(int depth, int start);
bool isConnected(const vector<pair<int,int>>& pos);

vector<pair<int, int>> pos;
char array[SIZE][SIZE];

// 상하좌우
int dy[DIRECTION] = {-1,1,0,0};
int dx[DIRECTION] = {0,0,-1,1};
int result = 0;

int main() {
    
    // 입력받기
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> array[i][j];
        }
    }
    // printArray(array);
    // 조합 만들기
    combination(0, 0);
    cout << result;
    
}

bool isConnected(const vector<pair<int,int>> &pos) {
    set<pair<int,int>> posSet(pos.begin(), pos.end());
    bool visited[SIZE][SIZE] = {false};
    int sCount = 0;
    int check = 1;

    // 첫 요소 값이 S인지 확인
    if (array[pos[0].first][pos[0].second] == 'S') {
        sCount += 1;
    }
    
    // 가로, 세로 연결인지 확인
    queue<pair<int,int>> q;
    visited[pos[0].first][pos[0].second] = true;
    q.push(pos[0]);

    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        int y = cur.first;
        int x = cur.second;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 범위 내에 있는지 체크
            if (0 > ny || 0 > nx || SIZE <= ny || SIZE <= nx)  continue;
            // 연결된 수 갱신 후 조합에 있는 좌표인지 확인
            if (!visited[ny][nx] && posSet.count({ny, nx}) > 0) {
                check += 1;
                q.push({ny, nx});
                visited[ny][nx] = true;
                // S인지 확인
                if (array[ny][nx] == 'S') sCount++;   
            }
            
        }
    }
    if (sCount >= 4 && check == 7) return true;
    else return false;
}

void combination(int depth, int start) {
    // basis part
    if (depth == 7) {
        if (isConnected(pos)) {
            result += 1;
        }
        return;
    }

    // inductive part
    for (int i = start; i < 25; i++) {
        int y = i / SIZE;
        int x = i % SIZE;
        pos.push_back({y, x});
        combination(depth + 1, i + 1);
        pos.pop_back();
    }
}

void printArray(char array[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << array[i][j];
        }
        cout << "\n";
    }
}