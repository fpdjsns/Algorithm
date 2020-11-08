/**
 * problem : https://www.acmicpc.net/problem/17144
 * time complexity : O(RCT)
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define CLOCK_DIRECTION 0
#define COUNTER_CLOCK_DIRECTION 1

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

// 오른쪽 아래 왼쪽 위 (시계방향)
pair<int,int> clock[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// 오른쪽 위 왼쪽 아래 (시계반대방향)
pair<int,int> counterClock[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int R, C, T;

// move arr[x][y]
void moveCleaner(const vector<vector<int>>& arr, 
                 vector<vector<int>>& newArr,
                 int x, int y, int index, int direction) {
    int nx, ny;
    if(direction == CLOCK_DIRECTION) {
        nx = x + clock[index].first;
        ny = y + clock[index].second;
    } else {
        nx = x + counterClock[index].first;
        ny = y + counterClock[index].second;
    }
    
    if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
        moveCleaner(arr, newArr, x, y, index+1, direction);
        return;
    }
    if(arr[nx][ny] == -1) return;

    newArr[nx][ny] = max(0, arr[x][y]);
    moveCleaner(arr, newArr, nx, ny, index, direction);
}

int main() {
    cin >> R >> C >> T;
   
    vector<vector<int>> arr(R, vector<int>(C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> arr[i][j];
        }
    }
    
    while(T--) {
        vector<vector<int>> newArr(R, vector<int>(C, 0));
        vector<pair<int,int>> cleaners;
        // dust 
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                int now = arr[i][j];
                
                if(now == -1) {
                    cleaners.push_back({i, j});
                    newArr[i][j] = -1;
                    continue;
                }
                if(now == 0) continue;
                
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if(newArr[nx][ny] == -1) continue;
                    newArr[nx][ny] += now / 5;
                    cnt++;
                }
                newArr[i][j] += now - (now/5)*cnt;
            }
        }
        arr = newArr;

        // cleaner
        moveCleaner(arr, newArr, 
                     cleaners[0].first, cleaners[0].second, 
                     0, COUNTER_CLOCK_DIRECTION);
        moveCleaner(arr, newArr, 
                     cleaners[1].first, cleaners[1].second, 
                     0, CLOCK_DIRECTION);
        arr = newArr;
    }
    
    int answer = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            answer += max(0, arr[i][j]);
        }
    }
    cout << answer << endl;
    
    return 0;
}
