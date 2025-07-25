#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define MAX 5
using namespace std;
vector<pair<int,int>> combiArray;
bool isConnected(const vector<pair<int,int>>& combi, char array[][MAX]);
int result = 0;

void printArray(char array[][MAX]);
void combination(int depth, int start);
char array[MAX][MAX];

int main() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> array[i][j];
        }
    }
    // printArray(array);
    combination(0,0);
    cout << result;
    return 0;
}

void combination(int depth, int start) {
    // basis part
    if (depth == 7) {
        if (isConnected(combiArray, array)) {
            result++;
        }
        return;
    }

    // inductive part
    for (int i = start; i < 25; i++) {
        int y = i / 5;
        int x = i % 5;

        combiArray.push_back({y, x});
        combination(depth + 1, i + 1);
        combiArray.pop_back();
        
    }
}

// 가로 세로 연결됐는지
bool isConnected (const vector<pair<int,int>> &combi, char array[][MAX]) {
    set<pair<int, int>> combiSet(combi.begin(), combi.end());
    bool visited[MAX][MAX] = {false};

    queue<pair<int, int>> q;
    q.push(combi[0]);
    visited[combi[0].first][combi[0].second] = true;
    
    int cnt = 1;
    int sCount = 0;

    if (array[combi[0].first][combi[0].second] == 'S') {
        sCount++;
    }
    

    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int y = cur.first;
        int x = cur.second;

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            // 방문 조건 벗어나는지 확인
            if (ny < 0 || ny >= MAX || nx < 0 || nx >= MAX) continue;
            // 올바른 조건 카운트
            if (!visited[ny][nx] && combiSet.count({ny, nx}) > 0) {
                visited[ny][nx]= true;
                q.push({ny, nx});
                cnt += 1;

                if (array[ny][nx] == 'S') sCount++;
            }
            
        }
    }
    return (cnt == 7 && sCount >= 4);
}

void printArray(char array[][MAX]) {
    for (int i = 0; i < MAX; i ++) {
        for (int j = 0; j < MAX; j++) {
            cout << array[i][j] << "";
        }
        cout << "\n";
    }
}