/**
 * problem : 
 * time complexity : O(NlogN)
 * algorithm : binary search
 */

class Solution {
    int getPower(vector<int>& mat) {
        int left = 0; 
        int right = mat.size() - 1;
        int power = 0;
        while(left <= right) {
            int m = (left + right)/2;
            if(mat[m] == 1) {
                power = m + 1;
                left = m + 1;
            }
            else right = m - 1;
        }
        return power;
    }
  
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> powers(mat.size()); // (power, index)
        for(int i=0; i<mat.size(); i++){
            powers[i] = {getPower(mat[i]), i};
        }
        sort(powers.begin(), powers.end());
        for(auto power: powers) {
        }
        vector<int> answer(k);
        for(int i=0; i<k; i++){
            answer[i] = powers[i].second;
        }
        return answer;
    }
};
