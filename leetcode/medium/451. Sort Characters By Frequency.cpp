/**
 * problem : https://leetcode.com/problems/sort-characters-by-frequency/
 * time complexity : O(NlogN)
 */

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        
        vector<pair<char,int>> arr;
        for(map<char, int>::iterator it = m.begin(); it != m.end(); it++) arr.push_back({it->first, it->second});
        
        sort(arr.begin(), arr.end(), [arr](pair<char,int>& a, pair<char,int>& b){
           return a.second > b.second; 
        });
        string ans;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].second;j++){
                ans.push_back(arr[i].first);
            }
        }
        return ans;
    }
};
