# problem : https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.ind = 0
        self.ans = []
        N = len(characters)
        def dfs(index, tempStr):
            if len(tempStr) == combinationLength:
                self.ans.append(tempStr)
                return
            if index >= N:
                return
            dfs(index+1, tempStr + characters[index])
            dfs(index+1, tempStr)
        dfs(0, "")

    def next(self) -> str:
        if self.ind >= len(self.ans):
            return None
        ans = self.ans[self.ind]
        self.ind +=1
        return ans

    def hasNext(self) -> bool:
        return self.ind < len(self.ans)


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
