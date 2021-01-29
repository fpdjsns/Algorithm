/**
 * problem : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * algorithm : dfs
 * time complexity : O(NlogN)
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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> m;
        queue<pair<pair<int, int>, TreeNode*>> q;
        q.push({{0, 0}, root});
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            TreeNode* node = q.front().second;
            q.pop();
            
            if(node == nullptr) continue;
            
            m[x].push_back({y, node->val});
            
            q.push({{x-1, y+1}, node->left});
            q.push({{x+1, y+1}, node->right});
        }
        
        vector<vector<int>> answer;
        for(map<int, vector<pair<int,int>>>::iterator now = m.begin();
           now != m.end(); now++){
            
            sort((now->second).begin(), (now->second).end());
            vector<int> tmp;
            for(vector<pair<int,int>>::iterator it = (now->second).begin();
               it != (now->second).end(); it++){
                tmp.push_back(it->second);
            }
            
            answer.push_back(tmp);
        }
        return answer;
    }
};
