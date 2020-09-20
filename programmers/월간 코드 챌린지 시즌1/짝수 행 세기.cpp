/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/68647
 * algorithm : DP
 * time complexity : O(N * M^2) // N = number of rows, M = number of columns
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long MOD = 1e7 + 19;
vector<vector<long long>> combi;

// nCr
long long getCombination(int n, int r) {
	if (n < r) return 0;
    long long& ret = combi[n][r];
	if (ret != -1) return ret;
	
	if (n == r || r == 0) return ret = 1;
	return ret = (getCombination(n - 1, r - 1) + getCombination(n - 1, r)) % MOD;
}

int solution(vector<vector<int>> arr) {
	int n = (int)arr.size();
	int m = (int)arr[0].size();
    combi = vector<vector<long long>>(301, vector<long long>(301, -1));
    
    // oneCnts[j] = j번째 열의 1의 개수
    vector<int> oneCnts(m+1, 0);
    for (int i = 0; i < n; i++)
        for (int j=0; j < m; j++)
		    oneCnts[j+1] += arr[i][j];
    
    // dp[column][num] = arr[0~n][0~column]까지 num개의 행이 짝수인 경우의 수
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    dp[1][n - oneCnts[1]] = getCombination(n, oneCnts[1]);
    
    for(int column = 1; column <= m; column++){
        int nowOneCnt = oneCnts[column]; // arr 배열에서 column 열의 1의 개수
        for (int beforeEvenCnt = 0; beforeEvenCnt <= n; beforeEvenCnt++){ // 이때까지 세팅한 짝수 행의 개수
            // 기존에 있던 행 중에 짝수개의 1을 가진 행에 1을 세팅하고자 하는 개수. 가전
            for (int willSetEvenRows = 0; willSetEvenRows <= nowOneCnt; willSetEvenRows++) { 
                // 기존에 있던 행 중 홀수개의 1을 가진 행에 1을 세팅하고자 하는 개수. = column 열이 가진 1의 개수 중 짝수개를 가진 행에 세팅할 1을 뺀 나머지.
                int willSetOddRow = nowOneCnt - willSetEvenRows; 
                // 1을 세팅하고 난 뒤 1을 짝수개 가진 행의 개수 = 짝수행 중 1을 세팅하지 않는 행 + 홀수행 중 1을 세팅하는 행
                int willBeEvenRowCnt = (beforeEvenCnt - willSetEvenRows) + willSetOddRow;
                if (willSetOddRow < 0 || willBeEvenRowCnt > n || willBeEvenRowCnt < 0) continue; // IMPOSSIBLE
                
                // 경우의 수 = 짝수행에 1을 세팅하는 경우의 수 * 홀수행에 1을 세팅하는 경우의 수 % MOD
                long long numOfCase = (getCombination(beforeEvenCnt, willSetEvenRows) * getCombination(n - beforeEvenCnt, willSetOddRow)) % MOD;
                dp[column][willBeEvenRowCnt] += dp[column-1][beforeEvenCnt] * numOfCase % MOD;
                dp[column][willBeEvenRowCnt] %= MOD;
            }
        }
    }
    
	return dp[m][n];
}
