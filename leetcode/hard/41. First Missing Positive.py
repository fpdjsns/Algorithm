# problem : https://leetcode.com/problems/first-missing-positive/
# time complexity : O(N)

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 1
        for num in nums:
            if(ans in s):
                ans += 1
            else:
                break
        return ans
