/**
 * problem : https://leetcode.com/problems/sort-the-people/
 * time complexity : O(NlogN)
 */
 
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<pair<int,int>> sortedHeights(n);
        for(int i=0; i<n; i++){
            sortedHeights[i] = {-heights[i], i};
        }
        sort(sortedHeights.begin(), sortedHeights.end());
        vector<string> answer(n);
        for(int i=0; i<n; i++){
            answer[i] = names[sortedHeights[i].second];
        }
        return answer;
    }
};
