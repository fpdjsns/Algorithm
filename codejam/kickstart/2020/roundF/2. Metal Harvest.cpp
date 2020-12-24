/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4b8b#problem
 * algorithm : two pointer
 * time complexity : O(NlogN)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> harvests(N);
        for(int i=0; i<N; i++){
            cin >> harvests[i].first >> harvests[i].second;
        }
        sort(harvests.begin(), harvests.end());
        
        int answer = 0;
        int canStart = 0;
        for(int i=0; i<N; i++){
            int start = max(harvests[i].first, canStart);
            
            if(harvests[i].second <= start) continue;
            // repeat
            int cnt = (harvests[i].second - start + K - 1);
            answer += cnt;
            canStart = start + (K * cnt);
        }
        printf("Case #%d: %d\n", t, answer);
    }
}

