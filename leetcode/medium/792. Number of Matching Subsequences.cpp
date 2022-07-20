/**
 * problem : https://leetcode.com/problems/number-of-matching-subsequences/
 * time complexity : O(MKlog(N)) (N = s.length, M = words.length, K = words[i].length)
 */
 
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charIndexes(26);
        
        for(int i=0; i<s.size(); i++){
            charIndexes[s[i]-'a'].push_back(i);
        }
        
        int answer = 0;
        for(auto word: words) {
            bool canAns = true;
            int index = -1;
            for(auto c: word) {
                vector<int>& indexes = charIndexes[(char)c-'a'];
                auto findInd = upper_bound(indexes.begin(), indexes.end(), index);
                if(findInd == indexes.end()){
                    canAns = false;
                    break;
                }
                index = indexes[findInd - indexes.begin()];
            }
            answer += canAns;
        }
        
        return answer;
    }
};
