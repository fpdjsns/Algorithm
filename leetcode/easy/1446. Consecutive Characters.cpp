/**
 * problem : https://leetcode.com/problems/consecutive-characters/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 0) 
            return 0;
        
        int answer = 1;
        int cnt = 1;
        for(int i=1; i<s.size(); i++) {
            if(s[i] == s[i-1]) 
                cnt++;
            else 
                cnt = 1;
            answer = max(answer, cnt);
        }
        return answer;
    }
};
