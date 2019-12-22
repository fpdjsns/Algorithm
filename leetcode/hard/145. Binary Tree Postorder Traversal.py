# problem : https://leetcode.com/problems/binary-tree-postorder-traversal/
# time complexity : O(N)
# data structure : stack

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:

        ans = []
        s = [(root, 0)]
        while len(s) > 0:
            node, appearCnt = s.pop()

            if node is None:
                continue

            if appearCnt == 0:
                s.append((node, 1))
                s.append((node.right, 0))
                s.append((node.left, 0))
            else:
                ans.append(node.val)
        return ans
