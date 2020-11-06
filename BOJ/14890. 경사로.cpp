/**
 * problem : https://www.acmicpc.net/problem/14890
 * time complexity : O(2*(N^2))
 */ 

#include <iostream>
#include <vector>

#define ROW 0
#define COLUMN 1

using namespace std;

int N, L;

bool canPass(vector<vector<int>>& arr, int start, bool direction) {
    int cnt = 1;
    for(int i=1;i<N; i++){
        int now = (direction == ROW) ? arr[start][i] : arr[i][start];
        int before = (direction == ROW) ? arr[start][i-1] : arr[i-1][start];
        
        if(now == before) { cnt++; continue; }
        if(abs(now-before) > 1) return false;
        if(cnt < 0) return false; 
        if(before < now) { if(cnt < L) return false; cnt = 1; }
        else { cnt = -L + 1; }
    }
    return cnt >= 0;
}


int main(){

    cin >> N >> L;
    vector<vector<int>> arr(N, vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    int answer = 0; 
    for(int i=0;i<N;i++){
        answer += canPass(arr, i, ROW) + canPass(arr, i, COLUMN);
    }
    cout << answer;
    return 0;
}
