/**
 * problem : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
 * time complexity : O(NlogN)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
	int MOD = 1e9 + 7;
	long long sum = 0;
	long long ans = 0;

	long long getSum(TreeNode* node) {
		if (node == NULL) return 0;
		long long sum = node->val;
		sum += getSum(node->left);
		sum += getSum(node->right);
		return sum;
	}

	long long setAns(TreeNode* node) {
		if (node == NULL) return 0;
        
        int now = node->val;
        now += setAns(node->left);
        now += setAns(node->right);
        
        ans = max(ans, (now * (sum - now)));
        return now;
	}

public:
	int maxProduct(TreeNode* root) {
		sum = getSum(root);
		setAns(root);
		return ans % MOD;
	}
};
