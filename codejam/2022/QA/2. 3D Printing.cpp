/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b
 * time complexity : O(1)
 */

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        
        vector<int> colors(4, 1e9);
        
        int color;
        for(int i=0; i<3; i++){
            for(int j=0; j<4; j++){
                cin >> color;
                colors[j] = min(colors[j], color);
            }
        }
        
        int sum = 1e6;
        for(int i=0; i<4; i++){
            colors[i] = min(colors[i], sum);
            sum -= colors[i];
        }
        
        
        if(sum > 0) {
            printf("Case #%d: IMPOSSIBLE\n", t);
            continue;
        }
        printf("Case #%d: %d %d %d %d\n", t, colors[0], colors[1], colors[2], colors[3]);
    }
    return 0;
}
