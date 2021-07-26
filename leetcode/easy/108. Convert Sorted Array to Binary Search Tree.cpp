/**
 * problem : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * time complexity : O(N) // N = |nums|
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* makeBST(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;
        int m = (left + right) / 2;
        return new TreeNode(nums[m], 
                            makeBST(nums, left, m-1),
                            makeBST(nums, m+1, right));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size() - 1);
    }
};
