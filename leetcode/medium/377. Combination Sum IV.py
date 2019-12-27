# problem : https://leetcode.com/problems/combination-sum-iv/
# time complexity : O(N^2)
# algorithm : dfs, memoization

class Solution:

    nums = []
    memoization = dict()
    def combinationSum4(self, nums: List[int], target: int) -> int:
        self.memoization = dict()
        self.nums = nums
        return self.dfs(target)

    def dfs(self, target: int) -> int:
        if target < 0:
            return 0
        if target == 0:
            return 1
        ret = self.memoization.get(target, -1)
        if ret != -1:
            return ret
        ret = 0
        for num in self.nums:
            ret += self.dfs(target - num)

        self.memoization[target] = ret
        return ret
