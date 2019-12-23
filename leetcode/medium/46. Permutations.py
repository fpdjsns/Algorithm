# problem : https://leetcode.com/problems/permutations/
# time complexity : O(N!)

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for ind, addNum in enumerate(nums):
            newAns = []
            for list in ans:
                for insertIndex in range(ind + 1):
                    tmpList = list.copy()
                    tmpList.insert(insertIndex, addNum)
                    newAns.append(tmpList)
            ans = newAns
        return ans
