/*
 * 문제 : https://leetcode.com/problems/longest-string-chain/
 * 시간복잡도 : O(NMlogN) // N : words.length, M : words[i].length
 * 알고리즘 : DP
 */
 
class Solution {
    
    static bool compare(string a, string b) {
        if(a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        map<string, int> dp; // string, longest length of a word chain
        int answer = 0;
        
        sort(words.begin(), words.end(), compare);
        for(int i=0; i<words.size(); i++) {
            string word2 = words[i];
            dp[word2] = 1;
            
            // delete one of alphabet at word2
            for(int j=0; j < word2.size(); j++){
                string word1 = word2;
                word1.erase(word1.begin()+j);
                if(word1.empty()) continue;
                map<string,int>:: iterator it = dp.find(word1);
                if(it == dp.end()) continue;
                dp[word2] = max(dp[word2], it->second + 1);
            }
            answer = max(answer, dp[word2]);
        }
        
        return answer;
    }
};
