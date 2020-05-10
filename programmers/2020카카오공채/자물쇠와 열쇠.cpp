/**
 * programmers - 2020카카오공채 - 자물쇠와 열쇠
 * problem : https://programmers.co.kr/learn/courses/30/lessons/60059
 * algorithm : simulation
 * time complexity : O((N+M)^2 * M^2)
 */

#include <string>
#include <vector>
#define IMPOSSIBLE -1
using namespace std;

int M, N;

// O(M^2)
int check(int x, int y, vector<vector<int>>& key, vector<vector<int>>& lock) {
    int cnt = 0;
    for(int i=max(0, x);i<min(x+M, N);i++){
        for(int j=max(0, y);j<min(y+M, N);j++){
            if(key[i-x][j-y] == 1 && lock[i][j] == 1) {
                return IMPOSSIBLE; 
            }
            cnt += key[i-x][j-y];
        }
    }
    return cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	M = key.size();
	N = lock.size();
	vector<vector<vector<int>>> keys(4, vector<vector<int>>(M, vector<int>(M)));
	for (int i = 0; i<M; i++) {
		for (int j = 0; j<M; j++) {
			keys[0][i][j] = key[i][j];
			keys[1][j][M - 1 - i] = key[i][j];
			keys[2][M - 1 - i][M - 1 - j] = key[i][j];
			keys[3][M - 1 - j][i] = key[i][j];
		}
	}

	int emptyCnt = 0;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			emptyCnt += lock[i][j];
		}
	}
	emptyCnt = N*N - emptyCnt;

	for (int x = -M; x<N; x++) {
		for (int y = -M; y<N; y++) {
			for (int d = 0; d<4; d++) {
				if (check(x, y, keys[d], lock) == emptyCnt) 
                    return true;
			}
		}
	}
	return false;
}
