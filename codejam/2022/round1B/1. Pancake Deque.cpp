/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000acd59d
 * time complexity : O(N)
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N; cin >> N;
        vector<int> D(N);
        for(int i=0; i<N; i++)
            cin >> D[i];
        int l = 0;
        int r = N-1;
        int answer = 0;
        int prev = 0;
        while(l <= r) {
            if(D[l] <= D[r]) {
                if(D[l] < prev) {
                    l++;
                    continue;
                }
                prev = D[l++];
            } else if (D[r] >= prev){
                prev = D[r--];
            } else {
                r--;
                continue;
            }
            answer++;
        }

        printf("Case #%d: %d\n", t, answer);
    }
    return 0;
}
