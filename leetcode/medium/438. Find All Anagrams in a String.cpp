/**
 * problem : https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * time complexity : O(N)
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> m;
        set<char> charters;
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
            charters.insert(p[i]);
        }
        
        vector<int> ans;
        int size = p.size();
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            char now = s[i];
            if(charters.find(now) != charters.end()) {
                if(m[now] > 0) cnt++;
                m[now]--;
            }
            if(i-size >= 0 && charters.find(s[i-size]) != charters.end()){
                char prev = s[i-size];
                if(m[prev] >= 0) cnt--;
                m[prev]++;
            }
            if(cnt == size) 
                ans.push_back(i-size+1);
        }
        return ans;
    }
};
