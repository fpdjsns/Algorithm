/**
 * problem : https://leetcode.com/problems/single-number-iii/
 * time complexity : O(N)
 * algorithm : bitmask
 */
 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        int N = nums.size();
        for(int i=0;i<N;i++){
            sum ^= nums[i];
        }
        
        int lastSettedBit = (sum & (sum - 1)) ^ sum;
        int ans = 0;
        for(int i=0;i<N;i++){
            if((int)(lastSettedBit & nums[i]) == 0)
                ans ^= nums[i];
        }
        
        return vector<int>{ ans, sum ^ ans };
    }
};
