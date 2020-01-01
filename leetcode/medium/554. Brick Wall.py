# problem: https://leetcode.com/problems/brick-wall/
# time complexity: O(NM)

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        lenDict = dict()
        for w in wall:
            wLen = 0
            for wallLen in w[:-1]:
                wLen += wallLen
                lenDict[wLen] = lenDict.get(wLen, 0) + 1

        maxCnt = 0
        for key, value in lenDict.items():
            maxCnt = max(maxCnt, value)

        return len(wall) - maxCnt
