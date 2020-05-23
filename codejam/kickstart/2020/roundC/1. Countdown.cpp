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
        vector<int> arr(N);
        int ans = 0;
        bool canAns = false;
        for(int i=0; i<N; i++){
            cin >> arr[i];
            
            if(arr[i] == K) {
                canAns = true;
            } else if(i>0){
                canAns &= (arr[i-1]-1 == arr[i]);
            }
            
            if(arr[i] == 1 && canAns) {
                canAns = false;
                ans++;
            }
        }
        
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
