/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b
 * time complexity : O(RC)
 */

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    int T, R, C;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> R >> C;
        
        printf("Case #%d:\n", t);
        for(int i=0; i<=2*R; i++) {
            for(int j=0; j<=2*C; j++) {
                char now;
                if(i < 2 && j < 2) now = '.';
                else if(i%2==0 && j%2==0) now = '+';
                else if(i%2==0 && j%2==1) now = '-';
                else if(i%2==1 && j%2==0) now = '|';
                else now = '.';
                
                cout << now;
            }
            cout << endl;
        }
    }
    return 0;
}
