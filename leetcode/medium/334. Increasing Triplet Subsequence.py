# problem : https://leetcode.com/problems/increasing-triplet-subsequence/
# time complexity : O(N)

import sys

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        one, two = nums[0], sys.maxsize
        for three in nums[1:]:
            if three > two:
                return True
            if three > one:
                two = three
            if three < one:
                one = three

        return False
