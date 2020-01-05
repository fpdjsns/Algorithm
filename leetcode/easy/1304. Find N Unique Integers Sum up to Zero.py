# problem : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
# time complexity : O(N/2)

class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        for i in range(1,n//2 + 1):
            ans.append(i)
            ans.append(-i)
        if n % 2 == 1:
            ans.append(0)
        return ans
