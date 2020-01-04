# problem : https://leetcode.com/problems/binary-tree-level-order-traversal/
# time complexity : O(N)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        q = []
        q.append(root)
        ans = []

        while len(q):
            qSize = len(q)
            values = []

            for _ in range(qSize):
                node = q.pop(0)
                values.append(node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            ans.append(values)
        return ans
