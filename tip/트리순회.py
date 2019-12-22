class Solution:

    # postorder
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        ans = []
        ans += self.postorderTraversal(root.left)
        ans += self.postorderTraversal(root.right)
        ans.append(root.val)
        return ans
