/**
 * problem : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
 * time complexity : O(N^2)
 */

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int answer = 0;
        for(int st=0; st < n; st++){
            unordered_map<int, int> cnts;
            for(int ed=st; ed < n; ed++) {
                cnts[s[ed]]++;
                int maxNum = 0; int minNum = 1e9;
                for(auto cnt: cnts) {
                    maxNum = max(maxNum, cnt.second);
                    minNum = min(minNum, cnt.second);
                }
                answer += maxNum - minNum;
            }
        }
        return answer;
    }
};
