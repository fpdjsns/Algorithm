/**
 * problem: https://leetcode.com/problems/largest-divisible-subset/
 * time complexity: O(N^2)
 * algorithm: DP
 */

class Solution {
private:
    vector<int> numArr = vector<int>();
    vector<int> nextInd = vector<int>(); //이전 index
    vector<int> dp = vector<int>();
    int size = 0;
    
public:
    // S[ind~] 배열에서 ind를 반드시 포함하는 subset의 최장 길이 
    int dfs(int ind) {
        int& ret = dp[ind];
        if(ret != -1) return ret;
        ret = 1; // myself

        int num = numArr[ind];
        if(ind == size-1) // last
            return ret;
        
        for(int i=ind+1; i<size;i++){
            if(numArr[i] % num != 0) continue;
            int tmpLen = dfs(i) + 1; // plus myself
            if(tmpLen > ret){
                ret = tmpLen;
                nextInd[ind] = i;
            }
        }
        return ret;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) 
            return vector<int>();
        
        sort(nums.begin(), nums.end());
        
        numArr = nums;
        size = nums.size();
        nextInd = vector<int>(size, -1);
        dp = vector<int>(size, -1);

        int maxLen = 0;
        int startInd = 0;
        for(int i=0;i<size;i++){
            int len = dfs(i);
            if(len <= maxLen) continue;
            maxLen = len;
            startInd = i;
        }

        // make Answer by nextInd array
        vector<int> ans = vector<int>();
        int ind = startInd;
        while(ind != -1){
            ans.push_back(nums[ind]);
            ind = nextInd[ind];
        }
        
        return ans;
    }
};
