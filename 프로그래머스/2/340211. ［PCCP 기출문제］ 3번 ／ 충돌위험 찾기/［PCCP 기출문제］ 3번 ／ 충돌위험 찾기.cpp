#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int robots = routes.size();
    map<int, vector<pair<int,int>>> path;
    
    // 각 위치에 로봇 배치
    for (int i = 0; i < robots; i++) {
        int curY, curX;
        int targetY, targetX;
        curY = points[routes[i][0] - 1][0];
        curX = points[routes[i][0] - 1][1];
        path[0].push_back({curY, curX});
        int time = 0;
        for (int j = 1; j < routes[i].size(); j++) {
            targetY = points[routes[i][j] - 1][0];
            targetX = points[routes[i][j] - 1][1];
            
            // Y먼저 이동 후 X 이동시키기
            while (curY != targetY) {
                if (curY < targetY) curY++;
                else curY--;
                time++;
                path[time].push_back({curY, curX});
                }
            while (curX != targetX) {
                if (curX < targetX) curX++;
                else curX--;
                time++;
                path[time].push_back({curY, curX});
                }
            }
        }
        // 충돌체크
        for (auto &p : path) {
            // 같은 시간에 같은 좌표 있는지 체크
            map<pair<int,int>, int> counter;
            for (auto &coord : p.second) {
                counter[coord]++;
            }
            // 여러 개 있는지 체크
            for (auto &c : counter) {
                if (c.second > 1) answer++;
            }
    // for (auto r: robotPos) {
    //     cout << r.first << " " << r.second << "\n";
    // }
    }
    return answer;
}