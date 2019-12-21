# problem : https://leetcode.com/problems/find-k-th-smallest-pair-distance/
# time complexity : O(NlogN + NlogM)

class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def count(mid: int):
            highInd = 1
            cnt = 0
            for lowInd in range(len(nums)):
                while highInd < len(nums) and nums[highInd] - nums[lowInd] <= mid:
                    highInd += 1
                cnt += max(0, (highInd - lowInd - 1))
            return cnt

        nums.sort()
        high = nums[-1] - nums[0]
        low = 0
        while low < high:
            mid = int((high + low)/2)
            cnt = count(mid)
            if cnt >= k:
                high = mid
            else:
                low = mid + 1
        return low
