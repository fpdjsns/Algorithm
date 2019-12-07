# 문제 : https://leetcode.com/problems/minimum-time-visiting-all-points/
# 시간복잡도 : O(N)

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        answer = 0
        for ind in range(len(points)-1):
            x = points[ind][0] - points[ind+1][0]  
            y = points[ind][1] - points[ind+1][1]  

            answer += max(abs(x), abs(y))

        return answer
