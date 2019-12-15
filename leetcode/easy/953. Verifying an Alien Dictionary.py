# 문제 : https://leetcode.com/problems/verifying-an-alien-dictionary/submissions/
# 시간복잡도 : O(M * NlogN + K) // N = |words|, M = |words[i]|, K = |order|

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        orderList = ['a'] * 26
        for ind in range(len(list(order))):
            orderList[ord(order[ind]) - ord('a')] =chr(ind + ord('a'))

        for ind in range(len(words)):
            newWord = ''
            for e in list(words[ind]):
                newWord += orderList[ord(e) - ord('a')]
            words[ind] = newWord
        return sorted(words) == words
