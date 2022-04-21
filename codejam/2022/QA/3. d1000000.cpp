/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471
 * time complexity : O(NlogN)
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
        vector<int> dices(N);
        for(int i=0; i<N; i++)
            cin >> dices[i];
        sort(dices.begin(), dices.end());
        
        int index = 0;
        int num;
        for(num=1; num<=N; num++){
            while(index < N && dices[index] < num) index++;
            if(index == N) {num--; break;}
            index++;
        }
        
        printf("Case #%d: %d\n", t, min(num, N));
    }
    return 0;
}
