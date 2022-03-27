/**
 * problem : https://codingcompetitions.withgoogle.com/codejamio/round/00000000009d9870/0000000000a33e95
 * time complexity : O((2N) ^ 2)
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

/**
 *
 * a b
 * c d

 * a + b = c + d
 * a + c = b + d

 * b - c = c - b
 * b = c
 * a = d
 */
 
int main() {
    int T;
    cin >> T;
    
    for(int t=1; t<=T; t++){
        int N; 
        cin >> N;
        
        int size = 2*N;
        vector<vector<char>> arr(size, vector<char>(size));
        
        vector<int> cnts(4, 0);
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                cin >> arr[i][j];
                
                if(i < N && j < N) cnts[0] += (arr[i][j] == 'I');
                else if(i< N && j >= N) cnts[1] += (arr[i][j] == 'I');
                else if(i>= N && j < N) cnts[2] += (arr[i][j] == 'I');
                else cnts[3] += (arr[i][j] == 'I');
            }
        }
        
        printf("Case #%d: %d\n", t, abs(cnts[0] - cnts[3]) + abs(cnts[1] - cnts[2]));
    }
    
    return 0;
}
