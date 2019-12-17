# 문제 : https://leetcode.com/problems/distribute-coins-in-binary-tree/
# 시간복잡도 : O(N)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        self.sumMoveCount = 0
        def getMoveCount(node: TreeNode) -> int:
            if not node:
                return 0

            moveCount = node.val
            moveCount += getMoveCount(node.left)
            moveCount += getMoveCount(node.right)
            moveCount -= 1

            self.sumMoveCount += abs(moveCount)
            return moveCount

        getMoveCount(root)
        return self.sumMoveCount
