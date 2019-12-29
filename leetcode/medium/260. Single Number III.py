# problem : https://leetcode.com/problems/single-number-iii/
# time complexity : O(N)

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        numDict = dict()  # numDict[num] = cnt

        for num in nums:
            cnt = numDict.get(num, 0)
            numDict[num] = cnt + 1

        ans = []
        for k, v in numDict.items():
            if v == 1:
                ans.append(k)
        return ans
