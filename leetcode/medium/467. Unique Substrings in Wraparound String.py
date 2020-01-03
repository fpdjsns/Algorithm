# problem : https://leetcode.com/problems/unique-substrings-in-wraparound-string/
# time complexity : O(N)

class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        lengths = [0]*26
        currentLength = 0
        for i in range(len(p)):
            now = ord(p[i])-97
            prev = ord(p[i-1])-97
            if i > 0 and (now - prev) % 26 == 1:
                currentLength += 1
            else:
                currentLength = 1
            lengths[now] = max(lengths[now], currentLength)
        return sum(lengths)
