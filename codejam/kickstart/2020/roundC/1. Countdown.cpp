/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003380d2
 * time complexity : O(N)
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
    int C; cin>>C;
    for(int tc=1;tc<=C;tc++){
        int N, K; 
        cin >> N >> K;
        
        int prev = -1;
        int now;
        int ans = 0;
        bool canAns = false;
        for(int i=0; i<N; i++){
            cin >> now;
            
            if(now == K) {
                canAns = true;
            } else {
                canAns &= (prev-1 == now);
            }
            
            if(now == 1 && canAns) {
                canAns = false;
                ans++;
            }
            
            prev = now;
        }
        
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
