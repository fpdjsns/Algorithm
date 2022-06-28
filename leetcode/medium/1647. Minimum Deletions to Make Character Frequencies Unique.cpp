/**
 * problem : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
 * time complexity : O(NlogN)
 */
 
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> cnts;
        for(auto c: s) cnts[c]++;
        vector<int> sorted;
        for(auto now: cnts) {
            sorted.push_back(now.second);
        }
        sort(sorted.begin(), sorted.end(), [](int& a, int& b) { return a > b; });
        int maxCnt = sorted[0];
        int answer = 0;
        for(auto cnt: sorted) {
            int tmp = max(0, cnt - maxCnt);
            answer += tmp;
            maxCnt = max(min(cnt - tmp, maxCnt) - 1, 0); 
        }
        return answer;
    }
};
