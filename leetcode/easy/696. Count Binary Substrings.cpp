/** 
 * problem : https://leetcode.com/problems/count-binary-substrings/
 * time complexity : O(N)
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> cnts = { 0, 0 };
        int answer = 0;
        cnts[s[0]-'0']++;
        for(int i=1; i < s.size(); i++){
            int now = s[i] - '0';
            if(s[i-1] == s[i]) {
                cnts[now]++;
            } else {
                cnts[now] = 1;
            }
            if(cnts[now] <= cnts[!now]) answer++;
        }
        return answer;
    }
};
