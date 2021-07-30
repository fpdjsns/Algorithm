/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/81302
 * algorithm : BFS
 * time complexity : O((NM)^2)
 */
#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX_DIST 2

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char PEOPLE = 'P';
char TABLE = 'O';
char PARTITION = 'X';

bool solution(vector<string> places) {
    
    int n = places.size(); 
    int m = places[0].size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(places[i][j] == PEOPLE) {
                queue<pair<int, int>> q;
                q.push({i, j});
                vector<vector<bool>> visits(n, vector<bool>(m, false));
                visits[i][j] = true;
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(visits[nx][ny] || abs(nx-i) + abs(ny-j) > MAX_DIST || places[nx][ny] == PARTITION) continue;
                        if(places[nx][ny] == PEOPLE) {
                            return false;
                        }
                        visits[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(places.size(), 0);
    for(int i=0; i < places.size(); i++) {
        answer[i] = solution(places[i]);
    }
    return answer;
}
