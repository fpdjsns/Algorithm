/**
 * problem : https://www.acmicpc.net/problem/16235
 * time complexity : O(N^2 + K + α)
 */
 
#include <iostream>
#include <vector>

#define START_FOOD 5
#define START_AGE 1
using namespace std;

int N, M, K;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
void pastYear(vector<vector<vector<int>>>& lands,
              vector<vector<int>>& feed,
              const vector<vector<int>>& A){
    // spring, summer, winter
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int k=lands[i][j].size()-1;
            // spring1
            for(; k >= 0; k--){
                if(feed[i][j] < lands[i][j][k]) break;
                feed[i][j] -= lands[i][j][k];
                lands[i][j][k]++;
            }
            // summer
            int dieCnt = k;
            for(; k>= 0; k--) {
                feed[i][j] += (lands[i][j][k]/2);
            }
            // spring2
            if(dieCnt >= 0) lands[i][j].erase(
                lands[i][j].begin(),
                lands[i][j].begin() + (dieCnt + 1));
            // winter
            feed[i][j] += A[i][j];
        }
    }
    // autumn
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(auto treeAge : lands[i][j]){
                if(treeAge % 5 != 0) continue;
                for(int k=0;k<8;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    lands[nx][ny].push_back(START_AGE);
                }
            }
        }
    }
}

int main(){
    // input
    cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    vector<vector<vector<int>>> lands(N, vector<vector<int>>(N));
    int x, y, z;
    for(int i=0;i<M;i++){
        cin >> x >> y >> z; 
        x--; y--;
        lands[x][y].push_back(z);
    }
    vector<vector<int>> feed(N, vector<int>(N, START_FOOD));
    
    // past K years
    for(int i=0;i<K;i++){
        pastYear(lands, feed, A);
    }
    
    // get number of trees
    int answer = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            answer += lands[i][j].size();
        }
    }
    cout << answer << endl;
    
    return 0;
}
