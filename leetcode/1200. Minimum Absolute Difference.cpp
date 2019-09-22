/*
 * 문제 : https://leetcode.com/problems/minimum-absolute-difference/
 * 시간복잡도 : O(NlogN)
 * 알고리즘 : Greedy
 */
 
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = 1e9;
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++){
            int a = arr[i-1];
            int b = arr[i];
            int nowDiff = b-a;
            
            if(diff > nowDiff)
                ans = vector<vector<int>>();
            
            if(diff >= nowDiff){
                diff = nowDiff;
                ans.push_back({a, b});
            }
        }
        return ans;
    }
};
