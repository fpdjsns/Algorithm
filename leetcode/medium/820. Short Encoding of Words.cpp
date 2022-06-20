/**
 * problem : https://leetcode.com/problems/short-encoding-of-words/
 * time complexity : O(NM) // N = words.size(), M = words[i].size();
 * algorithm : greedy
 */
 
class Solution {
    unordered_set<string> dict;
public:
    int minimumLengthEncoding(vector<string>& words) {
        int answer = 0;
        sort(words.begin(), words.end(), [](string& a, string& b){return a.size() < b.size();});
        for(int i=0; i<words.size(); i++){
            string& word = words[i];
            for(int j=0; j<word.size(); j++){
                string tmp = word.substr(j);
                if(dict.find(tmp) != dict.end()) {
                    dict.erase(tmp);
                    answer -= (tmp.size() + 1);
                    break;
                }
            }
            dict.insert(word);
            answer += (word.size()  + 1);
        }
        
        return answer;
    }
};
