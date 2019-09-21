/*
 * 문제 : https://leetcode.com/problems/flip-string-to-monotone-increasing
 * 시간복잡도 : O(N) 
 * 알고리즘 : Greedy
 */

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        
        int NOTYET = 0;
        
        int zeroCnt = NOTYET;
        int oneCnt = NOTYET;
        
        int lastOne = 0;
        
        for(int i=0;i<S.size();i++){
            if(S[i] == '0'){
                if(oneCnt == NOTYET) continue;
                zeroCnt++;
            }else{
                oneCnt++;
            }
            
            zeroCnt = min(zeroCnt, oneCnt);
        }
        
        return min(zeroCnt, oneCnt);
    }
};
