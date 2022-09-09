/**
 * problem : https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
 * time complexity : O(NlogN)
 * algorithm : greedy
 */
 
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        int answer = 0;
        int maxDepen = 0;
        for(auto prop: properties){
            if(prop[1] < maxDepen) answer++;
            maxDepen = max(maxDepen, prop[1]);
        }
        return answer;
    }
};
