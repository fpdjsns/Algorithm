# problem : https://leetcode.com/problems/word-break-ii/
# time complexity : O(NM)
# algorithm : DFS, DP

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        dict = {}
        for ele in list(wordDict):
            lastChar = list(ele)[len(ele)-1]
            dict.setdefault(lastChar, []).append(ele)

        dp = [None] * (len(s) + 1)
        def dfs(lastInd: int) -> List[str] :
            if lastInd < 0:
                return [""]

            if dp[lastInd] is not None:
                return dp[lastInd]

            dp[lastInd] = []

            lastChar = list(s)[lastInd]
            for word in dict.get(lastChar, []):
                firstInd = lastInd - len(word) + 1
                if s[firstInd:lastInd+1] == word:
                    for tmp in dfs(firstInd - 1):
                        dp[lastInd].append(tmp + ("" if tmp=="" else " ") + word)
            return dp[lastInd]

        return dfs(len(s) - 1)
