# 문제 : https://leetcode.com/problems/minimum-time-difference/
# 시간복잡도 : O(NlogN)

class Solution:

  def findMinDifference(self, timePoints: List[str]) -> int:

    list = []
    for timePoint in timePoints:
        time = timePoint.split(':')
        list.append(int(time[0])*60 + int(time[1]))
    list.sort()
    list.append(list[0] + 24*60)

    answer = 24*60
    for ind in range(len(list) - 1):
        answer = min(answer, list[ind + 1] - list[ind])

    return answer
