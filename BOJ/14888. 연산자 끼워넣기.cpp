/**
 * problem : https://www.acmicpc.net/problem/14888
 * time complexity : O(4^N)
 * algorithm : backtracking
 */
 
#include <iostream>
#include <vector>
#include <algorithm>

#define PLUS 0
#define MINUS 1
#define MULTIPLE 2
#define DIVISION 3

using namespace std;

int N;
pair<int, int> answer; // max, min

void solve(vector<int>& arr, vector<int>& signCnt, int ind, int result, int sign) {
    
    switch(sign) {
        case PLUS: result += arr[ind]; break;
        case MINUS: result -= arr[ind]; break;
        case MULTIPLE: result *= arr[ind]; break;
        case DIVISION: result /= arr[ind]; break;
        default: break;
    }
    
    if(ind == N-1) {
        answer = {max(answer.first, result), min(answer.second, result)};
        return;
    }
    
    for(int sign=0; sign<signCnt.size(); sign++){
        if(signCnt[sign] <= 0) continue;
        signCnt[sign]--;
        solve(arr, signCnt, ind+1, result, sign);
        signCnt[sign]++;
    }
}

int main(){
    cin >> N;
    vector<int> arr(N);
    answer = {-1e9, 1e9};
    for(int i=0; i<N; i++) cin>>arr[i];
    vector<int> signCnt(4);
    for(int i=0; i<signCnt.size(); i++) cin>>signCnt[i];
    
    solve(arr, signCnt, 0, 0, PLUS);
    cout << answer.first << endl << answer.second << endl;
    
    return 0;
}
