# problem : https://leetcode.com/problems/unique-number-of-occurrences/
# time complexity : O(NlogN)
# data structure : set, dictionary

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnts = dict()
        diffNum = set()
        for ele in arr:
            cnts[ele] = cnts.get(ele, 0) + 1
            diffNum.add(ele)
        s = set()
        for k, v in cnts.items():
            s.add(v)
        return len(s) == len(diffNum)
