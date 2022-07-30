/**
 * problem : https://leetcode.com/problems/word-subsets/
 * time complexity : O(|words1| + |words2|)
 */

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> cnts(26, 0);
        for(auto word: words2) {
            vector<int> nowCnts(26, 0);
            for(auto c: word) {
                int ind = c-'a';
                nowCnts[ind]++;
                cnts[ind] = max(cnts[ind], nowCnts[ind]);
            }
        }
        
        vector<string> answer;
        for(auto word: words1) {
            vector<int> nowCnts(26, 0);
            for(auto c: word) nowCnts[c-'a']++;
            int canAns = true;
            for(int i=0; i<26; i++) {
                if(nowCnts[i] >= cnts[i]) continue;
                canAns = false;
                break;
            }
            if(canAns) answer.push_back(word);
        }
        return answer;
    }
};
