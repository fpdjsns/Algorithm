/**
 * problem : https://leetcode.com/problems/set-mismatch/
 * time complexity : O(N)
 * space complexity : O(1)
 */
 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        long long squSum = 0;
        for(int num: nums) {
            sum += num;
            squSum += num * num;
        }
        
        int A = n * (n + 1) / 2 - sum;
        int B = (long long)n * (n + 1) * (2*n + 1) / 6 - squSum;
        
        int x = (A + B/A) / 2;
        int y = (B/A - A) / 2;
        
        return vector<int>{ y, x };
    }
};
