/**
 * problem : https://leetcode.com/problems/combinations/
 * time complexity : O(N! / (N-K)!) 
 * algorithm : backtracking
 */

class Solution {
    vector<vector<int>> answer;
    int N, K;
    void combine(int ind, vector<int>& arr) {
        if(arr.size() == K) {
            answer.push_back(arr);
            return;
        }
        
        for(; ind <= N; ind++){
            arr.push_back(ind);
            combine(ind+1, arr);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        N = n; K = k;
        answer.clear();
        vector<int> arr;
        combine(1, arr);
        return answer;
    }
};
