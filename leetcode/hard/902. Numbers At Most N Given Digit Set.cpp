/**
 * problem : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
 * time complexity : O(NM) (N = |n|, M = |digits|)
 */
 
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string maxStr = to_string(n);
        int strLen = maxStr.size();
        int digitCnt = digits.size();
        string str(strLen, '0');
        
        int answer = 0;
        for(int i=1; i<=strLen-1; i++){
            answer += pow(digitCnt, i);
        }
        
        for(int i=0; i<strLen; i++) {
            int j = 0;
            for(; j<digitCnt; j++) {
                if(digits[j][0] >= maxStr[i]) break;
                answer += pow(digitCnt, strLen - (i+1));
            }
            
            // after that, no possibility of correct answer 
            if(j == digitCnt || digits[j][0] != maxStr[i]) 
                break;
            
            // end of maxStr = exactly same
            if(i == strLen-1) answer++;
        }
        
        return answer;
    }
};
